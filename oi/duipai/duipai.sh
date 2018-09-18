#!/bin/bash

# subl pre//file/code_1.cpp
# subl pre//file/code_2.cpp

echo -n "Please input your makefile name in 'cpp' dir : "
read make

if find -name $make;then echo "Test start"
else echo "Please check your makefile"
	exit 0
fi

clang++ ./pre/code_1.cpp -o  ./pre/code_1
clang++ ./pre/code_2.cpp -o ./pre/code_2

while true; do
./make/cpp/$make > tmp.in
./pre/code_1 < ./file/tmp.in > ./file/code_1.out
./pre/code_2 < ./file/tmp.in > ./file/code_2.out
if diff ./file/code_2.out ./file/code_1.out;
	then printf AC
    else echo WA
         exit 0
fi
done