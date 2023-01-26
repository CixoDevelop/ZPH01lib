#!/bin/bash

SOURCE=../sources/sensor.c
TARGET=../build-gcc-arm/libZPH01.a
OBJECT=../build-gcc-arm/ZPH01lib.o

rm $TARGET -f

arm-none-eabi-gcc -mtune=cortex-m0plus -O2 $SOURCE -c -o $OBJECT
arm-none-eabi-ar -cq $TARGET $OBJECT 

rm $OBJECT
