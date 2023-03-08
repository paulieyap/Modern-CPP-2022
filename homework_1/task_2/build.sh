#!/usr/bin/env bash
mkdir -p ./build
mkdir -p results/bin
mkdir -p results/lib
c++ -c -I./include/ src/sum.cpp -o build/sum.o
c++ -c -I./include/ src/subtract.cpp -o build/subtract.o
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o
c++ -c -I./include/ src/main.cpp -o build/main.o
cp build/libipb_arithmetic.a results/lib
c++ build/main.o -L build/ -lipb_arithmetic -o results/bin/test_ipb_arithmetic