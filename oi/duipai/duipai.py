import filecmp
import os
import sys
import time


def init():
    path = os.path.abspath('.')
    name = input("Please input the file in 'python' dir name :")

    Check_Make_Path(path + '/make/python/' + name + ".py")

    spj = int(input("Enable special judge ( 1 -> YES , 0 -> NO) :"))
    tim = int(input("Please input the timelimits for the app (ms):")) / 1000
    # print (path)
    return spj, name, tim, path


def Check_Make_Path(path):
    if os.path.isfile(path):
        # return 1
        pass
    else:
        print("No file")
        exit()
        # return 0


def compile_():
    os.system("clang++ ./pre/code_1.cpp -o  ./pre/code_1")
    os.system("clang++ ./pre/code_2.cpp -o ./pre/code_2")
    if spj:
        os.system("clang++ ./spj/%s -o ./spj/%s" % (spjname + '.cpp', spjname))


def merge():
    filepath = os.path.abspath('.')
    fileout1 = open('./file/spjin_1.out', 'w')
    fileout2 = open('./file/spjin_2.out', 'w')
    for l in open(filepath + '/file/tmp.in'):
        fileout1.writelines(l)
        fileout2.writelines(l)
    for l in open(filepath + '/file/code_1.out'):
        fileout1.writelines(l)
    for l in open(filepath + '/file/code_2.out'):
        fileout2.writelines(l)
    fileout1.close()
    fileout2.close()


def compair(st):
    if st:
        merge()
        os.system("./spj/%s < ./file/spjin_1.out > ./file/spj1.out" % (spjname))
        os.system("./spj/%s < ./file/spjin_2.out > ./file/spj2.out" % (spjname))
        return filecmp.cmp("./file/spj1.out", "./file/spj2.out")
    else:
        return filecmp.cmp("./file/code_1.out", "./file/code_2.out")

#--------------------------------------------------------------#
spj, name, tim, path = init()
spjname = 0


if spj:
    spjname = input("Please input the file in 'spj' dir name :")
    Check_Make_Path(path + '/spj/' + spjname + '.cpp')


cnt = 0
mx = 1000


compile_()


print("Test start :")


while cnt < mx:
    os.system("python3 %s > ./file/tmp.in" % (path + '/make/python/' + name + ".py"))
    Time_A = time.time()
    os.system("./pre/code_1 < ./file/tmp.in > ./file/code_1.out")
    Time_B = time.time()
    os.system("./pre/code_2 < ./file/tmp.in > ./file/code_2.out")
    Time_C = time.time()
    cnt = cnt + 1

    print("The %d / %d group" % (cnt, mx))

    A = Time_B-Time_A
    B = Time_C-Time_B
    if A > tim or B > tim:
        print("TLE")
        print("Time for code_1 : %f " % A)
        print("Time for code_2 : %f " % B)
        break

    if compair(spj):
        print("AC")
    else:
        print("WA")
        break
    # print (Time_A)
    # print (Time_B)
    # print (Time_C)
    print("Time for code_1 : %f " % A)
    print("Time for code_2 : %f \n" % B)


if cnt == mx:
    print("You pass the test , but check out carefully !")
else:
    print("G G !")
