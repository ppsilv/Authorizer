#!/bin/bash

echo "This programa depends on libmicrohttp, if you do not have one installed into your system, please install"
echo "sudo apt install libmicrohttp"

g++ -o webService service.cpp -I . -L . -lhttpserver -lmicrohttpd

