// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package service

import (
	"encoding/protobuf/proto"
	"sync"
	"testing"
)

var onceEcho sync.Once

type Echo int

func (t *Echo) Echo(args *EchoRequest, reply *EchoResponse) error {
	reply.Msg = args.Msg
	return nil
}

func TestEcho(t *testing.T) {
	onceEcho.Do(func() {
		go ListenAndServeEchoService("tcp", ":2015", new(Echo))
	})
	client, stub, err := DialEchoService("tcp", "127.0.0.1:2015")
	if err != nil {
		t.Fatalf(`DialEchoService("tcp", "127.0.0.1:2015"): %v`, err)
	}
	defer client.Close()

	var args EchoRequest
	var reply EchoResponse

	// EchoService.Echo
	args.Msg = proto.String("Hello, Protobuf-RPC")
	if err = stub.Echo(&args, &reply); err != nil {
		t.Fatalf(`stub.Echo: %v`, err)
	}
	if reply.GetMsg() != args.GetMsg() {
		t.Fatalf(`stub.Echo: expected = "%s", got = "%s"`, args.GetMsg(), reply.GetMsg())
	}
}
