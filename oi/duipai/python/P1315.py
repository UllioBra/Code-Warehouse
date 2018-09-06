from cyaron import *
n = randint(2, 1000)
m = randint(1, 10000)
k = randint(1, 10000)
print(n, m, k)
for i in range(1, n):
    print(randint(0, 1000))
for i in range(3, m+3):
    A = randint(1, n-1)
    B = randint(A+1, n)
    print(randint(1000, 100000), A, B)