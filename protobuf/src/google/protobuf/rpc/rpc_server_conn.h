// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef GOOGLE_PROTOBUF_RPC_SERVER_CONN_H__
#define GOOGLE_PROTOBUF_RPC_SERVER_CONN_H__

#include <google/protobuf/rpc/rpc_env.h>
#include <google/protobuf/rpc/rpc_conn.h>
#include <google/protobuf/rpc/rpc_service.h>

namespace google {
namespace protobuf {
namespace rpc {

class Server;

class ServerConn {
 public:
  ServerConn(Server* server, Conn* conn, Env* env);
  ~ServerConn();

  void Serve();

 private:
  static void RunProc(void* p);
  void Run();

  const ::google::protobuf::rpc::Error callMethod(
    const std::string& method,
    const ::google::protobuf::Message* request,
    ::google::protobuf::Message* response);

  bool checkMothdValid(
    const std::string& method,
    const ::google::protobuf::Message* request,
    ::google::protobuf::Message* response) const;
  bool checkMothdValid(
    const ::google::protobuf::MethodDescriptor* method,
    const ::google::protobuf::Message* request,
    ::google::protobuf::Message* response) const;

  bool genWireHeader(
    const std::string& method,
    ::google::protobuf::rpc::wire::Header* header);
  bool genWireHeader(
    const ::google::protobuf::MethodDescriptor* method,
    ::google::protobuf::rpc::wire::Header* header);

  bool readRequestHeader(::google::protobuf::rpc::wire::Header* header);
  bool readRequestBody(::google::protobuf::Message* request);
  bool writeResponse(
    const ::google::protobuf::rpc::wire::Header* header,
    const ::google::protobuf::Message* response);

  Server* server_;
  Conn* conn_;
  Env* env_;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ServerConn);
};

}  // namespace rpc
}  // namespace protobuf
}  // namespace google

#endif  // GOOGLE_PROTOBUF_RPC_SERVER_CONN_H__

