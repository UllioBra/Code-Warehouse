import sys
import os
import filecmp
import time

name = input("Please input the file in 'python' dir name :")
path = os.path.abspath('.') + '/python/' + name + ".py"
# print (path)

if os.path.isfile(path) :
    pass
else : 
    print("No file")
    exit()

os.system("clang++ ./pre/juruo.cpp -o  ./pre/juruo")
os.system("clang++ ./pre/std.cpp -o ./pre/std")

mx = 1000
cnt = 0
print ("Test start :")

while cnt < mx :
    os.system("python3 %s > tmp.in" %path)
    # Time_A = time.clock()
    os.system("./pre/juruo < tmp.in > juruo.out")
    # Time_B = time.clock()
    os.system("./pre/std < tmp.in > std.out")
    # Time_C = time.clock()
    cnt = cnt + 1
    print ("The %d / %d group" %(cnt,mx))
    if filecmp.cmp("juruo.out","std.out") :
        print ("AC")
    else :
        print ("WA")
        break
    # print (Time_A)
    # print (Time_B)
    # print (Time_C)
    # A = Time_B-Time_A
    # B = Time_C-Time_B
    # print ("Time for juruo : %f " %A)
    # print ("Time for std : %f \n" %B)

if cnt == mx :
    print ("You pass the test , but check out carefully!")
else :
    print ("G G !")
