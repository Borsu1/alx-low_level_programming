#!/bin/bash
wget -p .. https://githubusercontent.com/Borsu1/alx-low_level_programming/8f29ac4a0b04b5d27c85fcec8667aca34fda56dc/0x18-dynamic_libraries/libtest.so
export LD_PRELOAD="$PWD/../libtest.so"
