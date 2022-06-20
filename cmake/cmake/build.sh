#!/bin/bash
ROOT_DIR=$(cd `dirname $0`;pwd)
BUILD_DIR=$ROOT_DIR/out/build 
# rm -rf $BUILD_DIR/*
mkdir -p $BUILD_DIR
echo ------------BOARD_TYPE=$1-----------------------
cd $BUILD_DIR && cmake -DBOARD_TYPE=$1  $ROOT_DIR && make -j64 VERBOSE=1 && make install