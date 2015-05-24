# Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

project(PROTOBUF)

#------------------------------------------------------------------------------
# google protobuf

if(WIN32)
  include_directories(AFTER
    ./vsprojects
    ./src
  )
else(WIN32)
  include_directories(AFTER
    ./linux
    ./src
  )
endif(WIN32)

set(PB_SRC
  ./src/google/protobuf/io/coded_stream.cc
  ./src/google/protobuf/stubs/common.cc
  ./src/google/protobuf/descriptor.cc
  ./src/google/protobuf/descriptor.pb.cc
  ./src/google/protobuf/descriptor_database.cc
  ./src/google/protobuf/dynamic_message.cc
  ./src/google/protobuf/extension_set.cc
  ./src/google/protobuf/extension_set_heavy.cc
  ./src/google/protobuf/generated_message_reflection.cc
  ./src/google/protobuf/generated_message_util.cc
  ./src/google/protobuf/io/gzip_stream.cc
  ./src/google/protobuf/compiler/importer.cc
  ./src/google/protobuf/message.cc
  ./src/google/protobuf/message_lite.cc
  ./src/google/protobuf/stubs/once.cc
  ./src/google/protobuf/compiler/parser.cc
  ./src/google/protobuf/io/printer.cc
  ./src/google/protobuf/reflection_ops.cc
  ./src/google/protobuf/repeated_field.cc
  ./src/google/protobuf/service.cc
  ./src/google/protobuf/stubs/structurally_valid.cc
  ./src/google/protobuf/stubs/strutil.cc
  ./src/google/protobuf/stubs/substitute.cc
  ./src/google/protobuf/text_format.cc
  ./src/google/protobuf/io/tokenizer.cc
  ./src/google/protobuf/unknown_field_set.cc
  ./src/google/protobuf/wire_format.cc
  ./src/google/protobuf/wire_format_lite.cc
  ./src/google/protobuf/io/zero_copy_stream.cc
  ./src/google/protobuf/io/zero_copy_stream_impl.cc
  ./src/google/protobuf/io/zero_copy_stream_impl_lite.cc

  # xml support
  ./src/google/protobuf/xml/xml_message.cc
)

set(PBC_SRC
  ./src/google/protobuf/compiler/main.cc
  ./src/google/protobuf/compiler/code_generator.cc
  ./src/google/protobuf/compiler/command_line_interface.cc
  ./src/google/protobuf/compiler/subprocess.cc
  ./src/google/protobuf/compiler/zip_writer.cc
  ./src/google/protobuf/compiler/plugin.cc
  ./src/google/protobuf/compiler/plugin.pb.cc

  ./src/google/protobuf/compiler/cpp/cpp_enum.cc
  ./src/google/protobuf/compiler/cpp/cpp_enum_field.cc
  ./src/google/protobuf/compiler/cpp/cpp_extension.cc
  ./src/google/protobuf/compiler/cpp/cpp_field.cc
  ./src/google/protobuf/compiler/cpp/cpp_file.cc
  ./src/google/protobuf/compiler/cpp/cpp_generator.cc
  ./src/google/protobuf/compiler/cpp/cpp_helpers.cc
  ./src/google/protobuf/compiler/cpp/cpp_message.cc
  ./src/google/protobuf/compiler/cpp/cpp_message_field.cc
  ./src/google/protobuf/compiler/cpp/cpp_primitive_field.cc
  ./src/google/protobuf/compiler/cpp/cpp_service.cc
  ./src/google/protobuf/compiler/cpp/cpp_string_field.cc

  ./src/google/protobuf/compiler/java/java_enum.cc
  ./src/google/protobuf/compiler/java/java_enum_field.cc
  ./src/google/protobuf/compiler/java/java_extension.cc
  ./src/google/protobuf/compiler/java/java_field.cc
  ./src/google/protobuf/compiler/java/java_file.cc
  ./src/google/protobuf/compiler/java/java_generator.cc
  ./src/google/protobuf/compiler/java/java_helpers.cc
  ./src/google/protobuf/compiler/java/java_message.cc
  ./src/google/protobuf/compiler/java/java_message_field.cc
  ./src/google/protobuf/compiler/java/java_primitive_field.cc
  ./src/google/protobuf/compiler/java/java_service.cc
  ./src/google/protobuf/compiler/java/java_string_field.cc
  ./src/google/protobuf/compiler/python/python_generator.cc

  # add by chaishushan{AT}gmail.com
  ./src/google/protobuf/compiler/cxx/cxx_enum.cc
  ./src/google/protobuf/compiler/cxx/cxx_enum_field.cc
  ./src/google/protobuf/compiler/cxx/cxx_extension.cc
  ./src/google/protobuf/compiler/cxx/cxx_field.cc
  ./src/google/protobuf/compiler/cxx/cxx_file.cc
  ./src/google/protobuf/compiler/cxx/cxx_generator.cc
  ./src/google/protobuf/compiler/cxx/cxx_helpers.cc
  ./src/google/protobuf/compiler/cxx/cxx_message.cc
  ./src/google/protobuf/compiler/cxx/cxx_message_field.cc
  ./src/google/protobuf/compiler/cxx/cxx_primitive_field.cc
  ./src/google/protobuf/compiler/cxx/cxx_service.cc
  ./src/google/protobuf/compiler/cxx/cxx_string_field.cc
)

# rpc
set(PB_RPC_HDR
  ./src/google/protobuf/rpc/wire.pb/wire.pb.h
  ./src/google/protobuf/rpc/rpc_service.h
  ./src/google/protobuf/rpc/rpc_server.h
  ./src/google/protobuf/rpc/rpc_server_conn.h
  ./src/google/protobuf/rpc/rpc_client.h

  ./src/google/protobuf/rpc/rpc_conn.h
  ./src/google/protobuf/rpc/rpc_env.h
)
set(PB_RPC_SRC
  ./src/google/protobuf/rpc/wire.pb/wire.pb.cc
  ./src/google/protobuf/rpc/rpc_service.cc
  ./src/google/protobuf/rpc/rpc_server.cc
  ./src/google/protobuf/rpc/rpc_server_conn.cc
  ./src/google/protobuf/rpc/rpc_client.cc

  ./src/google/protobuf/rpc/rpc_conn.cc
  ./src/google/protobuf/rpc/rpc_env.cc
)

#------------------------------------------------------------------------------

add_library(pblib STATIC
  ${PB_SRC}
  ${PB_RPC_SRC}
)
if(CMAKE_BUILD_TYPE STREQUAL "debug")
  set_target_properties(pblib
    PROPERTIES OUTPUT_NAME "protobufd"
  )
else()
  set_target_properties(pblib
    PROPERTIES OUTPUT_NAME "protobuf"
  )
endif()

add_executable(protoc
  ${PBC_SRC}
)
target_link_libraries(protoc pblib)
if(UNIX)
  target_link_libraries(protoc pthread)
endif(UNIX)

#------------------------------------------------------------------------------

# xml test
add_executable(xmltest
  ./src/google/protobuf/xml/example/xml.pb/XmlTest.pb.h
  ./src/google/protobuf/xml/example/xml.pb/XmlTest.pb.cc
  ./src/google/protobuf/xml/example/xmltest.cc
)
target_link_libraries(xmltest pblib)

# rpc test
add_executable(rpctest
  ./src/google/protobuf/rpc/service.pb/arith.pb.h
  ./src/google/protobuf/rpc/service.pb/arith.pb.cc
  ./src/google/protobuf/rpc/service.pb/echo.pb.h
  ./src/google/protobuf/rpc/service.pb/echo.pb.cc
  ./src/google/protobuf/rpc/example/rpctest.cc

  ${PB_RPC_HDR}
  ${PB_RPC_SRC}
)
add_executable(rpcserver
  ./src/google/protobuf/rpc/service.pb/arith.pb.h
  ./src/google/protobuf/rpc/service.pb/arith.pb.cc
  ./src/google/protobuf/rpc/service.pb/echo.pb.h
  ./src/google/protobuf/rpc/service.pb/echo.pb.cc
  ./src/google/protobuf/rpc/example/rpcserver.cc

  ${PB_RPC_HDR}
  ${PB_RPC_SRC}
)
add_executable(rpcclient
  ./src/google/protobuf/rpc/service.pb/arith.pb.h
  ./src/google/protobuf/rpc/service.pb/arith.pb.cc
  ./src/google/protobuf/rpc/service.pb/echo.pb.h
  ./src/google/protobuf/rpc/service.pb/echo.pb.cc
  ./src/google/protobuf/rpc/example/rpcclient.cc

  ${PB_RPC_HDR}
  ${PB_RPC_SRC}
)
target_link_libraries(rpctest pblib)
target_link_libraries(rpcserver pblib)
target_link_libraries(rpcclient pblib)

#------------------------------------------------------------------------------

install(TARGETS pblib protoc xmltest rpctest rpcserver rpcclient
  RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
  LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
  ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

#------------------------------------------------------------------------------


