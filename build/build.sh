#!/bin/bash
cd ../bin

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

export CC=/usr/local/bin/gcc
export CXX=/usr/local/bin/g++


echo ${CURRENT_DIR}

# cmake ../
cmake ../ -G "Unix Makefiles" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -DBINARY_BITS=64

make