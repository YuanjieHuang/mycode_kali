#!/bin/bash
set -x
dir="./build"
[ -d "$dir" ] && rm -rf "$dir"
mkdir "$dir"
cd "$dir"
cmake ..
make all
# make install