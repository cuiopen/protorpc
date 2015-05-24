// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package protorpc

import (
	"encoding/protobuf/proto"
	"errors"
	"net"
	"net/rpc"
	"sync"
	"testing"

	// can not import xxx.pb with rpc stub here,
	// because it will cause import cycle.
	msg "net/rpc/protorpc/message.pb"
)

var onceAll sync.Once

type Arith int

func (t *Arith) Add(args *msg.ArithRequest, reply *msg.ArithResponse) error {
	reply.C = proto.Int32(args.GetA() + args.GetB())
	return nil
}

func (t *Arith) Mul(args *msg.ArithRequest, reply *msg.ArithResponse) error {
	reply.C = proto.Int32(args.GetA() * args.GetB())
	return nil
}

func (t *Arith) Div(args *msg.ArithRequest, reply *msg.ArithResponse) error {
	if args.GetB() == 0 {
		return errors.New("divide by zero")
	}
	reply.C = proto.Int32(args.GetA() / args.GetB())
	return nil
}

func (t *Arith) Error(args *msg.ArithRequest, reply *msg.ArithResponse) error {
	return errors.New("ArithError")
}

type Echo int

func (t *Echo) Echo(args *msg.EchoRequest, reply *msg.EchoResponse) error {
	reply.Msg = args.Msg
	return nil
}

func TestAll(t *testing.T) {
	onceAll.Do(func() {
		go listenAndServeArithAndEchoService("tcp", ":1414")
	})

	conn, err := net.Dial("tcp", "127.0.0.1:1414")
	if err != nil {
		t.Fatalf(`net.Dial("tcp", "127.0.0.1:1414"): %v`, err)
	}
	client := rpc.NewClientWithCodec(NewClientCodec(conn))
	defer client.Close()

	testArithClient(t, client)
	testEchoClient(t, client)
}

func listenAndServeArithAndEchoService(network, addr string) error {
	clients, err := net.Listen(network, addr)
	if err != nil {
		return err
	}
	srv := rpc.NewServer()
	if err := srv.RegisterName("ArithService", new(Arith)); err != nil {
		return err
	}
	if err := srv.RegisterName("EchoService", new(Echo)); err != nil {
		return err
	}
	for {
		conn, err := clients.Accept()
		if err != nil {
			return err
		}
		go srv.ServeCodec(NewServerCodec(conn))
	}
	panic("unreachable")
}

func testArithClient(t *testing.T, client *rpc.Client) {
	var args msg.ArithRequest
	var reply msg.ArithResponse
	var err error

	// Add
	args.A = proto.Int32(1)
	args.B = proto.Int32(2)
	if err = client.Call("ArithService.Add", &args, &reply); err != nil {
		t.Fatalf(`arith.Add: %v`, err)
	}
	if reply.GetC() != 3 {
		t.Fatalf(`arith.Add: expected = %d, got = %d`, 3, reply.GetC())
	}

	// Mul
	args.A = proto.Int32(2)
	args.B = proto.Int32(3)
	if err = client.Call("ArithService.Mul", &args, &reply); err != nil {
		t.Fatalf(`arith.Mul: %v`, err)
	}
	if reply.GetC() != 6 {
		t.Fatalf(`arith.Mul: expected = %d, got = %d`, 6, reply.GetC())
	}

	// Div
	args.A = proto.Int32(13)
	args.B = proto.Int32(5)
	if err = client.Call("ArithService.Div", &args, &reply); err != nil {
		t.Fatalf(`arith.Div: %v`, err)
	}
	if reply.GetC() != 2 {
		t.Fatalf(`arith.Div: expected = %d, got = %d`, 2, reply.GetC())
	}

	// Div zero
	args.A = proto.Int32(1)
	args.B = proto.Int32(0)
	if err = client.Call("ArithService.Div", &args, &reply); err.Error() != "divide by zero" {
		t.Fatalf(`arith.Error: expected = "%s", got = "%s"`, "divide by zero", err.Error())
	}

	// Error
	args.A = proto.Int32(1)
	args.B = proto.Int32(2)
	if err = client.Call("ArithService.Error", &args, &reply); err.Error() != "ArithError" {
		t.Fatalf(`arith.Error: expected = "%s", got = "%s"`, "ArithError", err.Error())
	}
}

func testEchoClient(t *testing.T, client *rpc.Client) {
	var args msg.EchoRequest
	var reply msg.EchoResponse
	var err error

	// EchoService.Echo
	args.Msg = proto.String("Hello, Protobuf-RPC")
	if err = client.Call("EchoService.Echo", &args, &reply); err != nil {
		t.Fatalf(`arith.Add: %v`, err)
	}
	if reply.GetMsg() != args.GetMsg() {
		t.Fatalf(`arith.Add: expected = "%s", got = "%s"`, args.GetMsg(), reply.GetMsg())
	}
}
