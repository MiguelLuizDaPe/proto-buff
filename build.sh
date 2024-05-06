#!/usr/bin/env sh

cc='clang++ -std=c++20'
cflags='-O1 -g -pipe -Wall -Wextra'

set -xe

$cc $cflags lib.cpp -o buff
./buff

