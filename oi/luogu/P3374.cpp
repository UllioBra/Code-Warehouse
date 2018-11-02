#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
 
#define ll long long
#define ull unsigned long long
 
using namespace std;

struct BIT {
    int le;
    int bitArr[501000];
    void init() {
        int j;
        for(int i = 1; i <= le; i++) {
            j = i + (i & -i);
            if(j < le) {
                bitArr[j] += bitArr[i];
            }
        }
    }

    void update(int idx,const int&k) {
        while(idx < le) {
            bitArr[idx] += k;
            idx = idx + (idx & -idx);
        }
    }

    int prefixsum(int idx) {
        int result = 0;
        while(idx > 0) {
            result += bitArr[idx];
            idx = idx - (idx & -idx);
        }

        return result;
    }

    int rangeSum(const int&f_idx,const int&t_dix) {
        return prefixsum(t_dix) - prefixsum(f_idx-1);
    }
}JR;

int n,m;

int main() {
    scanf("%d%d",&n,&m);
    JR.le = n+1;
    for(int i = 1; i <= n; i++)
        scanf("%d",&JR.bitArr[i]);
    JR.init();
    int a,b,c;
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d",&a,&b,&c);
        if(a == 1) {
            JR.update(b,c);
        } else {
            printf("%d\n",JR.rangeSum(b,c));
        }
    }
}