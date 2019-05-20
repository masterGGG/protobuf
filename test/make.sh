#########################################################################
# File Name: make.sh
# Author: ian
# mail: ian@taomee.com
# Created Time: Fri 17 May 2019 12:55:27 AM CST
#########################################################################
#!/bin/bash

SRC_DIR=./
DST_DIR=./

protoc -I=./ --python_out=./ ./data.proto
protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/data.proto
g++ -g -o xxx client.cpp data.pb.cc `pkg-config --libs --cflags protobuf`
