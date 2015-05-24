// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package service

import (
	"encoding/protobuf/proto"
	"errors"
	"sync"
	"testing"
)

var onceArith sync.Once

type Arith int

func (t *Arith) Add(args *ArithRequest, reply *ArithResponse) error {
	reply.C = proto.Int32(args.GetA() + args.GetB())
	return nil
}

func (t *Arith) Mul(args *ArithRequest, reply *ArithResponse) error {
	reply.C = proto.Int32(args.GetA() * args.GetB())
	return nil
}

func (t *Arith) Div(args *ArithRequest, reply *ArithResponse) error {
	if args.GetB() == 0 {
		return errors.New("divide by zero")
	}
	reply.C = proto.Int32(args.GetA() / args.GetB())
	return nil
}

func (t *Arith) Error(args *ArithRequest, reply *ArithResponse) error {
	return errors.New("ArithError")
}

func TestArith(t *testing.T) {
	onceArith.Do(func() {
		go ListenAndServeArithService("tcp", ":2010", new(Arith))
	})
	client, stub, err := DialArithService("tcp", "127.0.0.1:2010")
	if err != nil {
		t.Fatalf(`DialArithService("tcp", "127.0.0.1:2010"): %v`, err)
	}
	defer client.Close()

	var args ArithRequest
	var reply ArithResponse

	// Add
	args.A = proto.Int32(1)
	args.B = proto.Int32(2)
	if err = stub.Add(&args, &reply); err != nil {
		t.Fatalf(`arith.Add: %v`, err)
	}
	if reply.GetC() != 3 {
		t.Fatalf(`arith.Add: expected = %d, got = %d`, 3, reply.GetC())
	}

	// Mul
	args.A = proto.Int32(2)
	args.B = proto.Int32(3)
	if err = stub.Mul(&args, &reply); err != nil {
		t.Fatalf(`arith.Mul: %v`, err)
	}
	if reply.GetC() != 6 {
		t.Fatalf(`arith.Mul: expected = %d, got = %d`, 6, reply.GetC())
	}

	// Div
	args.A = proto.Int32(13)
	args.B = proto.Int32(5)
	if err = stub.Div(&args, &reply); err != nil {
		t.Fatalf(`arith.Div: %v`, err)
	}
	if reply.GetC() != 2 {
		t.Fatalf(`arith.Div: expected = %d, got = %d`, 2, reply.GetC())
	}

	// Div zero
	args.A = proto.Int32(1)
	args.B = proto.Int32(0)
	if err = stub.Div(&args, &reply); err.Error() != "divide by zero" {
		t.Fatalf(`arith.Div: expected = "%s", got = "%s"`, "divide by zero", err.Error())
	}

	// Error
	args.A = proto.Int32(1)
	args.B = proto.Int32(2)
	if err = stub.Error(&args, &reply); err.Error() != "ArithError" {
		t.Fatalf(`arith.Error: expected = "%s", got = "%s"`, "ArithError", err.Error())
	}
}
