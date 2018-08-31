#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <set>
#define ll long long
#define ull unsigned long long
#define io_F std::ios::sync_with_stdio(false)
using namespace std;

int le = 1;
int book[9] = {0,1,10,100,1000,10000,100000,1000000,10000000};
bool mp[100000001];

inline bool check(int x) {
    while (x / book[le] >= 10) le++;
    if (!(le % 2) && le != 2) return false;
    int tmp = le;
    while (tmp > 1) {
        if (x % 10 != x / book[tmp]) return false;
        x %= book[tmp];
        x /= 10;
        tmp -= 2;
    }
    return true;
}

int main () {
    int a,b;
    scanf("%d%d",&a,&b);
    if(b>9999999) b=9999999;
    for (int i = 3; i <= b; i += 2)
        if (!mp[i]) {
            if (i >= a && check(i)) 
                printf("%d\n",i);
            if (i < sqrt(b))
                for (int j = i + i + i; j <= b; j += i + i)
                    mp[j] = 1;
        }
    return 0;
}