#!/bin/bash

SOURCE=../sources/sensor.c
TARGET=../build-linux-gcc/ZPH01lib.a
OBJECT=../build-linux-gcc/ZPH01lib.o

gcc -O2 $SOURCE -c -o $OBJECT
ar -cq $TARGET $OBJECT 

rm $OBJECT
