#!/bin/bash
wget -p .. https://githubusercontent.com/Borsu1/alx-low_level_programming/master/0x18-dynamic_libraries/libtest.so
export LD_PRELOAD="$PWD/../libtest.so"
