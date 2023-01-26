#!/bin/bash

SOURCE=../sources/sensor.c
TARGET=../build-linux-gcc/libZPH01.a
OBJECT=../build-linux-gcc/ZPH01lib.o

rm $TARGET -f

arm-none-eabi-gcc -mtune=cortex-m0plus -O2 $SOURCE -c -o $OBJECT
arm-none-eabi-ar -cq $TARGET $OBJECT 

rm $OBJECT
