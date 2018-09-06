#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long
#define ci const int&
#define cl const long long&
#define cul const unsigned long long&
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

const int mod = 1e9 + 7;
int h, w ;
int A, B ;
ull le[200010];

inline ull ksm (int x, int y) {
    ull bs = x, ans = 1;
    while (y) {
        if (y & 1) ans *= bs;
        if (ans >= mod) ans %= mod;
        bs *= bs;
        if (bs >= mod) bs %= mod;
        y >>= 1;
    }
    return ans;
}

inline ull C (int x, int y) {
    ull a1 = le[x];
    ull b1 = (le[y] * le[x-y]) % mod;
    b1 = ksm(b1, mod-2);
    return (a1*b1) % mod;
}

int main() {
    scanf("%d %d %d %d", &h, &w, &A, &B);
    ull ans = 0;
    le[0] = 1; le[0] = 1;
    for (int i = 1; i <= h+w; i++) {
        le[i] = le[i-1] * i;
        if (le[i] >= mod) le[i] %= mod;
    }
    for (int i = B; i <= w - 1; i++) {
        ans += (C(i+h-A-1,i)*C(A-1+w-i-1,A-1));
        ans %= mod;
    }
    printf("%llu",ans);
    return 0;
}