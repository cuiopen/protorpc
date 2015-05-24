
@rem gen cxx code
..\..\..\..\..\bin\protoc.exe --cxx_out=. arith.proto
..\..\..\..\..\bin\protoc.exe --cxx_out=. echo.proto
..\..\..\..\..\bin\protoc.exe --cxx_out=. message.proto

@rem gen go code
..\..\..\..\..\bin\protoc.exe --go_out=. arith.proto
..\..\..\..\..\bin\protoc.exe --go_out=. echo.proto
..\..\..\..\..\bin\Debug\protoc.exe --go_out=. message.proto

@rem ..\..\..\..\..\bin\protoc.exe -h
