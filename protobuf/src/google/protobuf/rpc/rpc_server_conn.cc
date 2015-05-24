// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "google/protobuf/rpc/rpc_server_conn.h"
#include <google/protobuf/rpc/rpc_server.h>
#include <google/protobuf/stubs/defer.h>

namespace google {
namespace protobuf {
namespace rpc {

ServerConn::ServerConn(Server* server, Conn* conn, Env* env):
  server_(server), conn_(conn), env_(env) {
  //
}
ServerConn::~ServerConn() {
  conn_->Close();
  delete conn_;
}

void ServerConn::Serve() {
  env_->StartThread(ServerConn::RunProc, this);
}

// [static]
void ServerConn::RunProc(void* p) {
  auto self = (ServerConn*)p;
  self->Run();
  delete self;
}

void ServerConn::Run() {
  for(;;) {
    // 1. read header
    wire::Header hdr;
    if(!readRequestHeader(&hdr)) {
      env_->Logf("readRequestHeader fail.\n");
      return;
    }

    // 2. read raw body data
    std::string body;
    if(!conn_->ReadProtoData(&body)) {
      env_->Logf("ReadProtoData fail.\n");
      return;
    }

    // 3. find service/method
    auto method = server_->FindMethodDescriptor(hdr.method());
    if(method == NULL) {
      hdr.set_error("Can't find ServiceMethod: " + hdr.method());
      writeResponse(&hdr, NULL);
      continue;
    }
    auto service = server_->FindService(hdr.method());
    if(service == NULL) {
      hdr.set_error("Can't find ServiceMethod: " + hdr.method());
      if(!writeResponse(&hdr, NULL)) {
        env_->Logf("writeResponse fail.\n");
        return;
      }
      continue;
    }

    // 4. make request/response message
    auto request = service->GetRequestPrototype(method).New();
    auto response = service->GetResponsePrototype(method).New();
    defer([&](){ delete request; delete response; });

    // 5. parse body data
    if(!request->ParseFromString(body)) {
      hdr.set_error("Bad body: " + hdr.method());
      if(!writeResponse(&hdr, NULL)) {
        env_->Logf("writeResponse fail.\n");
        return;
      }
      continue;
    }

    // 6. call method
    auto err = service->CallMethod(method, request, response);
    if(!err.IsNil()) {
      hdr.set_error(err.String());
      if(!writeResponse(&hdr, NULL)) {
        env_->Logf("writeResponse fail.\n");
        return;
      }
      continue;
    }

    // 7. send response
    if(!writeResponse(&hdr, response)) {
      env_->Logf("writeResponse fail.\n");
      return;
    }
  }
}

bool ServerConn::readRequestHeader(::google::protobuf::rpc::wire::Header* header) {
  if(!conn_->ReadProto(static_cast<::google::protobuf::Message*>(header))) {
    return false;
  }
  return true;
}
bool ServerConn::readRequestBody(::google::protobuf::Message* request) {
  if(!conn_->ReadProto(static_cast<::google::protobuf::Message*>(request))) {
    return false;
  }
  return true;
}
bool ServerConn::writeResponse(
  const ::google::protobuf::rpc::wire::Header* header,
  const ::google::protobuf::Message* response
) {
  if(!conn_->WritePorto(header)) {
    return false;
  }
  if(!conn_->WritePorto(response)) {
    return false;
  }
  return true;
}

}  // namespace rpc
}  // namespace protobuf
}  // namespace google

