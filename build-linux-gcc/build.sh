#!/bin/bash

SOURCE=../sources/sensor.c
TARGET=../build-linux-gcc/libZPH01.a
OBJECT=../build-linux-gcc/ZPH01lib.o

rm $TARGET

gcc -O2 $SOURCE -c -o $OBJECT
ar -cq $TARGET $OBJECT 

rm $OBJECT
