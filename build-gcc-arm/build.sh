#!/bin/bash

SOURCE=../sources/sensor.c
TARGET=../build-linux-gcc/ZPH01lib.a
OBJECT=../build-linux-gcc/ZPH01lib.o

arm-none-eabi-gcc -mtune=cortex-m0 -O2 $SOURCE -c -o $OBJECT
arm-none-eabi-ar -cq $TARGET $OBJECT 

rm $OBJECT
