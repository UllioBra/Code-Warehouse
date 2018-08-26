#!/bin/bash

# subl pre/juruo.cpp
# subl pre/std.cpp
# clang++ ./pre/juruo.cpp -o  juruo
# clang++ ./pre/std.cpp -o std

echo -n "Please input your makefile name in 'c++' dir : "
read make

if find -name $make;then echo "Test start"
else echo "Please check your makefile"
	exit 0
fi

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