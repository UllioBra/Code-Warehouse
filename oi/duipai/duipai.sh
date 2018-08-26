#!/bin/bash

# subl pre/juruo.cpp
# subl pre/std.cpp

echo -n "Please input your makefile name in 'c++' dir : "
read make

if find -name $make;then echo "Test start"
else echo "Please check your makefile"
	exit 0
fi

clang++ ./pre/juruo.cpp -o  ./pre/juruo
clang++ ./pre/std.cpp -o ./pre/std

while true; do
./c++/$make>tmp.in
./pre/juruo<tmp.in>juruo.out
./pre/std<tmp.in>std.out
if diff std.out juruo.out;
	then printf AC
    else echo WA
         exit 0
fi
done