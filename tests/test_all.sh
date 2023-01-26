#!/bin/bash

../build-linux-gcc/build.sh

gcc -L../build-linux-gcc ../tests/test.c -o ../tests/test -I../headers -lZPH01
../tests/test
rm ../tests/test
