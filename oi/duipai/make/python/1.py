from cyaron import *

n = randint(1, 5000)
m = min(1000000, randint(1, n*(n-1)))
print(0, n, m)
st = [[0 for i in range(n)] for j in range(n) ]
for i in range(m):
    a = randint(1, n)
    b = randint(1, n)
    while(a == b or st[a][b] == 1):
        a = randint(1, n)
        b = randint(1, n)
    st[a][b] = 1;
    print(a, b)
