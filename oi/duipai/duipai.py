import filecmp
import os
import sys
import time


def init():
    spj = int(input("Enable special judge ( 1 -> YES , 0 -> NO) :"))
    name = input("Please input the file in 'python' dir name :")
    tim = int(input("Please input the timelimits for the app (ms):")) / 1000
    path = os.path.abspath('.')
    # print (path)
    return spj, name, tim, path


def Check_Make_Path(path):
    if os.path.isfile(path):
        return 1
    else:
        print("No file")
        return 0


def compile_():
    os.system("clang++ ./pre/juruo.cpp -o  ./pre/juruo")
    os.system("clang++ ./pre/std.cpp -o ./pre/std")
    if spj:
        os.system("clang++ ./spj/%s -o ./spj/%s" % (spjname + '.cpp', spjname))


def compair(st):
    if st:
        os.system("./spj/%s < juruo.out > spj1.out" % (spjname))
        os.system("./spj/%s < std.out > spj2.out" % (spjname))
        return filecmp.cmp("spj1.out", "spj2.out")
    else:
        return filecmp.cmp("juruo.out", "std.out")

#--------------------------------------------------------------#
spj, name, tim, path = init()
spjname = 0


if Check_Make_Path(path + '/make/python/' + name + ".py"):
    pass
else:
    exit()


if spj:
    spjname = input("Please input the file in 'spj' dir name :")
    if Check_Make_Path(path + '/spj/' + spjname + '.cpp'):
        pass
    else:
        exit()


cnt = 0
mx = 1000


compile_()


print("Test start :")


while cnt < mx:
    os.system("python3 %s > tmp.in" % (path + '/make/python/' + name + ".py"))
    Time_A = time.time()
    os.system("./pre/juruo < tmp.in > juruo.out")
    Time_B = time.time()
    os.system("./pre/std < tmp.in > std.out")
    Time_C = time.time()
    cnt = cnt + 1

    print("The %d / %d group" % (cnt, mx))

    A = Time_B-Time_A
    B = Time_C-Time_B
    if A > tim or B > tim:
        print("TLE")
        print("Time for juruo : %f " % A)
        print("Time for std : %f " % B)
        break

    if compair(spj):
        print("AC")
    else:
        print("WA")
        break
    # print (Time_A)
    # print (Time_B)
    # print (Time_C)
    print("Time for juruo : %f " % A)
    print("Time for std : %f \n" % B)


if cnt == mx:
    print("You pass the test , but check out carefully !")
else:
    print("G G !")
