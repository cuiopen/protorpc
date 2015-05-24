Fork from bitbucket.org and I need it produces service codes.

# For Go Users

Download and Install (can't use `go get`):

	hg clone https://bitbucket.org/chai2010/protorpc

or

	hg clone https://code.google.com/p/protorpc/ 

- Add `${protorpc_root}/gopath` to `$GOPATH`
- Add `${protorpc_root}/gopath/bin` to `$PATH`

Build `protoc-gen-go` and Run test:

	go install encoding/protobuf/protoc-gen-go
	go test net/rpc/protorpc/service.pb
	go test net/rpc/protorpc

**Note:** `${protorpc_root}/gopath/bin/protoc.exe` is `2.4.1` version.

## How to use (from `net/rpc/protorpc/doc.go`)

Package `net/rpc/protorpc` implements a Protobuf-RPC `ClientCodec` and `ServerCodec` for the `rpc` package.

Here is a simple proto file("arith.pb/arith.proto"):

	package arith;
	
	// At least one of xx_generic_services is true
	option cc_generic_services = true;
	option java_generic_services = true;
	option py_generic_services = true;
	
	message ArithRequest {
		optional int32 a = 1;
		optional int32 b = 2;
	}
	
	message ArithResponse {
		optional int32 val = 1;
		optional int32 quo = 2;
		optional int32 rem = 3;
	}
	
	service ArithService {
		rpc multiply (ArithRequest) returns (ArithResponse);
		rpc divide (ArithRequest) returns (ArithResponse);
	}

Then use "protoc-gen-go" to generate "arith.pb.go" file(include rpc stub):

	$ go install encoding/protobuf/protoc-gen-go
	$ cd arith.pb && protoc --go_out=. arith.proto

The server calls (for TCP service):

	package server
	
	import (
		"encoding/protobuf/proto"
		"errors"
	
		"./arith.pb"
	)
	
	type Arith int
	
	func (t *Arith) Multiply(args *arith.ArithRequest, reply *arith.ArithResponse) error {
		reply.Val = proto.Int32(args.GetA() * args.GetB())
		return nil
	}
	
	func (t *Arith) Divide(args *arith.ArithRequest, reply *arith.ArithResponse) error {
		if args.GetB() == 0 {
			return errors.New("divide by zero")
		}
		reply.Quo = proto.Int32(args.GetA() / args.GetB())
		reply.Rem = proto.Int32(args.GetA() % args.GetB())
		return nil
	}
	
	func main() {
		arith.ListenAndServeArithService("tcp", ":1984", new(Arith))
	}

At this point, clients can see a service "Arith" with methods "Arith.Multiply" and "Arith.Divide". To invoke one, a client first dials the server:

	client, stub, err := arith.DialArithService("tcp", "127.0.0.1:1984")
	if err != nil {
		log.Fatal(`arith.DialArithService("tcp", "127.0.0.1:1984"):`, err)
	}
	defer client.Close()

Then it can make a remote call with stub:

	var args ArithRequest
	var reply ArithResponse
	
	args.A = proto.Int32(7)
	args.B = proto.Int32(8)
	if err = stub.Multiply(&args, &reply); err != nil {
		log.Fatal("arith error:", err)
	}
	fmt.Printf("Arith: %d*%d=%d", args.GetA(), args.GetB(), reply.GetVal())

Is very simple to use "Protobuf-RPC" with "protoc-gen-go" tool. Try it out.

# For C++ Users

1. Install Cmake and VS2010(Windows)/gcc(Unix)
2. cd `${protorpc_root}/protobuf` and build with cmake


**Note:** `${protorpc_root}/protobuf` is based on `protobuf-2.4.x` version.

## Add Go's defer operator support

Some Examples:

	#include <google/protobuf/stubs/defer.h>
	
	FILE* fp = fopen("foo.txt", "rt");
	if(fp == NULL) return false;
	defer([&](){ printf("fclose(fp)\n"); fclose(fp); });
	
	char* buf = new char[1024];
	defer([&](){ printf("delete buf\n"); delete[] buf; });
	
	defer([](){ printf("defer a: %d\n", __LINE__); });
	defer([](){ printf("defer a: %d\n", __LINE__); });
	defer([](){ printf("defer a: %d\n", __LINE__); });
	
	{
		defer([](){ printf("defer b: %d\n", __LINE__); });
		defer([](){ printf("defer b: %d\n", __LINE__); });
		defer([](){ printf("defer b: %d\n", __LINE__); });
	}
	
	defer([](){
		printf("defer c:\n");
		for(int i = 0; i < 3; ++i) {
			defer([&](){ defer([&](){
				printf("\ti = %d: begin\n", i);
				defer([&](){ printf("\ti = %d\n", i); });
				printf("\ti = %d: end\n", i);
			});});
		}
	});

Reference:

- http://golang.org/doc/effective_go.html#defer
- http://golang.org/ref/spec#Defer_statements
- http://blog.korfuri.fr/post/go-defer-in-cpp/
- http://blog.korfuri.fr/attachments/go-defer-in-cpp/defer.hh
- http://blogs.msdn.com/b/vcblog/archive/2011/09/12/10209291.aspx

## Add xml support (with `--cxx_out` option):

	// Parse a protocol buffer contained in a string.
	bool ParseFromXmlString(const string& data);
	// Like ParseFromXmlString(), but accepts messages that are missing
	// required fields.
	bool ParsePartialFromXmlString(const string& data);
	
	// Serialize the message and store it in the given string.  All required
	// fields must be set.
	bool SerializeToXmlString(string* output) const;
	// Like SerializeToXmlString(), but allows missing required fields.
	bool SerializePartialToXmlString(string* output) const;

Here is the simple code(`${protorpc_root}/protobuf/src/google/protobuf/xml/example/xmltest.cc`):

	#include <stdio.h>
	
	#include "./xml.pb/XmlTest.pb.h"
	
	int main() {
		google::protobuf::xml::PbXmlTest pb1;
		google::protobuf::xml::PbXmlTest pb2;
		
		pb1.set_b(true);
		pb1.set_i(1001);
		pb1.set_f(0.123f);
		pb1.set_e(google::protobuf::xml::PB_VALUE_TYPE_INT);
		pb1.mutable_m()->set_b(false);
		pb1.mutable_m()->set_i(145);
		
		std::string xmlString;
		bool rv1 = pb1.SerializeToXmlString(&xmlString);
		printf("pb1 xml:\n%s\n", xmlString.c_str());
		
		bool b = pb2.ParseFromXmlString(xmlString);
		printf("pb2 dbg string:\n%s\n", pb2.DebugString().c_str());
		
		return 0;
	}

## Implement `Protobuf-RPC` (with `--cxx_out` option):

C++ use the same protocol as Go, so we can communication with C++ and Go with `Protobuf-RPC`.

Here is a simple proto file(`${protorpc_root}/protobuf/src/google/protobuf/rpc/service.pb`):

	package service;
	
	option cc_generic_services = true;
	option java_generic_services = true;
	option py_generic_services = true;
	
	message EchoRequest {
		optional string msg = 1;
	}
	
	message EchoResponse {
		optional string msg = 1;
	}
	
	service EchoService {
		rpc echo (EchoRequest) returns (EchoResponse);
	}
	
	service EchoServiceA {
		rpc echo (EchoRequest) returns (EchoResponse);
	}
	
	service EchoServiceB {
		rpc echo (EchoRequest) returns (EchoResponse);
	}

Then use new `protoc` with `--cxx_out` option to generate "arith.pb.{h|cc}" file(include rpc stub):

	${protorpc_root}/protobuf/bin/protoc --cxx_out=. echo.proto

The server calls (for TCP service):

	#include "echo.pb.h"
	
	class EchoService: public service::EchoService {
	public:
		inline EchoService() {}
		virtual ~EchoService() {}
	
		virtual const ::google::protobuf::rpc::Error Echo(
			const ::service::EchoRequest* request,
			::service::EchoResponse* response
		) {
			response->set_msg(request->msg());
			return ::google::protobuf::rpc::Error::Nil();
		}
	};
	
	
	int main() {
		::google::protobuf::rpc::Server server;
	
		server.AddService(new EchoService, true);
	
		server.Serve(9527);
	}

At this point, clients can see a service `EchoService` with methods `EchoService.Echo`. To invoke one, a client first dials the server:

	#include <google/protobuf/rpc/rpc_server.h>
	#include <google/protobuf/rpc/rpc_client.h>

	#include "arith.pb.h"

	int main() {
		::google::protobuf::rpc::Client client("127.0.0.1", 9527);
		
		service::EchoService::Stub echoStub(&client);
	
		::service::EchoRequest echoArgs;
		::service::EchoResponse echoReply;
		::google::protobuf::rpc::Error err;
	
		// EchoService.echo
		echoArgs.set_msg("Hello Protobuf-RPC!");
		err = echoStub.echo(&echoArgs, &echoReply);
		if(!err.IsNil()) {
			fprintf(stderr, "echoStub.echo: %s\n", err.String().c_str());
			return -1;
		}
		if(echoReply.msg() != echoArgs.msg()) {
			fprintf(stderr, "echoStub.echo: expected = \"%s\", got = \"%s\"\n",
				echoArgs.msg().c_str(), echoReply.msg().c_str()
			);
			return -1;
		}
	
		// EchoService.echo: Use Client
		echoArgs.set_msg("Hello Protobuf-RPC!");
		err = client.CallMethod("EchoService.Echo", &echoArgs, &echoReply);
		if(!err.IsNil()) {
			fprintf(stderr, "EchoService.echo: %s\n", err.String().c_str());
			return -1;
		}
		if(echoReply.msg() != echoArgs.msg()) {
			fprintf(stderr, "EchoService.echo: expected = \"%s\", got = \"%s\"\n",
				echoArgs.msg().c_str(), echoReply.msg().c_str()
			);
			return -1;
		}
	
		return 0;
	}

# Other

Please report bugs to <chaishushan{AT}gmail.com>.
Thanks!
