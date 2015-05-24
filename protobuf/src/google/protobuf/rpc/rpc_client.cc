// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "google/protobuf/rpc/rpc_client.h"

namespace google {
namespace protobuf {
namespace rpc {

Client::Client(const char* host, int port, Env* env):
  conn_(0,env), host_(host), port_(port), seq_(0) {
  //
}
Client::~Client() {
  Close();
}

const ::google::protobuf::rpc::Error Client::CallMethod(
  const std::string& method,
  const ::google::protobuf::Message* request,
  ::google::protobuf::Message* response
) {
  if(!checkMothdValid(method, request, response)) {
    return ::google::protobuf::rpc::Error::New(
      std::string("Client: Invalid method, method: ") + method
    );
  }
  return callMethod(method, request, response);
}

const ::google::protobuf::rpc::Error Client::CallMethod(
  const ::google::protobuf::MethodDescriptor* method,
  const ::google::protobuf::Message* request,
  ::google::protobuf::Message* response
) {
  if(!checkMothdValid(method, request, response)) {
    return ::google::protobuf::rpc::Error::New(
      std::string("Client: Invalid method, method: ") + Service::GetServiceMethodName(method)
    );
  }
  return callMethod(Service::GetServiceMethodName(method), request, response);
}

// Close the connection
void Client::Close() {
  conn_.Close();
}

// --------------------------------------------------------

const ::google::protobuf::rpc::Error Client::callMethod(
  const std::string& method,
  const ::google::protobuf::Message* request,
  ::google::protobuf::Message* response
) {
  if(!conn_.IsValid()) {
    if(!conn_.DialTCP(host_.c_str(), port_)) {
      return ::google::protobuf::rpc::Error::New(
        std::string("Client: DialTCP fail, ") +
        std::string("host: ") + host_ + std::string(":") + std::to_string(static_cast<long long>(port_))
      );
    }
  }

  ::google::protobuf::rpc::wire::Header header_out;
  ::google::protobuf::rpc::wire::Header header_in;
  genWireHeader(method, &header_out);

  if(!writeRequest(&header_out, request)) {
    Close();
    return ::google::protobuf::rpc::Error::New(
      std::string("Client: writeRequest failed, method: ") + method
    );
  }
  if(!readResponseHeader(&header_in)) {
    Close();
    return ::google::protobuf::rpc::Error::New(
      std::string("Client: readResponseHeader failed, method: ") + method
    );
  }
  if(header_in.seq() != header_out.seq()) {
    Close();
    return ::google::protobuf::rpc::Error::New(
      std::string("Client: readResponseHeader header seq error, method: ") + method
    );
  }
  if(!readResponseBody(response)) {
    Close();
    return ::google::protobuf::rpc::Error::New(
      std::string("Client: readResponseBody failed, method: ") + method
    );
  }

  return ::google::protobuf::rpc::Error::New(header_in.error());
}

// --------------------------------------------------------

bool Client::checkMothdValid(
  const std::string& method,
  const ::google::protobuf::Message* request,
  ::google::protobuf::Message* response
) const {
  if(method.empty()) return false;
  if(!request) return false;
  if(!response) return false;
  return true;
}
bool Client::checkMothdValid(
  const ::google::protobuf::MethodDescriptor* method,
  const ::google::protobuf::Message* request,
  ::google::protobuf::Message* response
) const {
  if(!method) return false;
  if(!request) return false;
  if(!response) return false;
  if(method->input_type() != request->GetDescriptor()) return false;
  if(method->output_type() != response->GetDescriptor()) return false;
  return true;
}

bool Client::genWireHeader(
  const std::string& method,
  ::google::protobuf::rpc::wire::Header* header
) {
  header->Clear();
  header->set_method(method);
  header->set_seq(seq_++);
  return true;
}
bool Client::genWireHeader(
  const ::google::protobuf::MethodDescriptor* method,
  ::google::protobuf::rpc::wire::Header* header
) {
  header->Clear();
  header->set_method(Service::GetServiceMethodName(method));
  header->set_seq(seq_++);
  return true;
}

bool Client::writeRequest(
  const ::google::protobuf::rpc::wire::Header* header,
  const ::google::protobuf::Message* request
) {
  if(!conn_.WritePorto(header)) {
    return false;
  }
  if(!conn_.WritePorto(request)) {
    return false;
  }
  return true;
}

bool Client::readResponseHeader(::google::protobuf::rpc::wire::Header* header) {
  if(!conn_.ReadProto(static_cast<::google::protobuf::Message*>(header))) {
    return false;
  }
  return true;
}

bool Client::readResponseBody(::google::protobuf::Message* request) {
  if(!conn_.ReadProto(static_cast<::google::protobuf::Message*>(request))) {
    return false;
  }
  return true;
}

}  // namespace rpc
}  // namespace protobuf
}  // namespace google

