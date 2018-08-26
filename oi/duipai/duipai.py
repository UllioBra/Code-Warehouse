import sys,os,filecmp

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

mx = 100
cnt = 0
print ("Test start :")

while cnt < mx :
    os.system("python3 %s > tmp.in" %path)
    os.system("./pre/juruo < tmp.in > juruo.out")
    os.system("./pre/std < tmp.in > std.out")
    cnt = cnt + 1
    print ("The %d / %d group" %(cnt,mx))
    if filecmp.cmp("juruo.out","std.out") :
        print ("AC")
    else :
        print ("WA")
        break

if cnt == mx :
    print ("You pass the test , but check out carefully!")
else :
    print ("G G !")
