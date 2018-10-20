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
int a, b, c, d;
ll hig[5005];

ll ksm(ll bs, ll x) {
    if(!bs) return 0;
    ll ans = 1;
    while(x) {
        if(x&1) ans *= bs;
        if(ans >= mod) ans %= mod;
        bs *= bs;
        if(bs >= mod) bs %= mod;
        x <<= 1;
    }
    return ans;
}

ll C(ll y, ll x) {
    if(x == y) return 1;
    ll a = hig[x];
    ll b = (hig[y] * hig[x-y]) % mod;
    return (a*ksm(b,mod-2)) % mod;
}

ll print(ll x, ll y, ll z) {
    // cout << x << ' ' << y << ' ' << z << endl;
    return ((x * y) % mod * z) % mod;
}


ll deal(int x, int y, int id) {
    if (!x || ! y) return 0;
    ll tmp1 = 0, tmp2 = 0;
    if (id == 1) tmp1 = 1;
    if (id == 2) tmp2 = 1;
    ll t = C(x-1, c-1) * C(y-1, d-1);
    t %= mod;
    ll s = C(x-1+tmp1, a-c+x-1+tmp1) * C(y-1+tmp2, b-d+y-1+tmp2);
    s %= mod;
    return (t*s) % mod;
}

int main() {
    /*
    C(c+d-1,a+d-1) * C(a+d-1,a+b-1) * C(c,c+d)
    */
    cin >> a >> b >> c >> d;
    hig[0] = 1;
    for (int i = 1; i <= 5000; i++) (hig[i] = hig[i-1] * i) %= mod;
    int mx = min(c, d);
    ll ans = 0;
    for (int i = 1; i <= mx; i++) {
        ans += deal(i, i, 1) + deal(i, i, 2);
        ans += deal(i, i-1, 0);
        ans += deal(i-1, i, 0);
        ans %= mod;
        // cout << ans << endl;
    }
    if (c > d) {
        ans += deal(d+1, d, 0);
    } else if(c < d) {
        ans += deal(d, d+1, 0);
    }
    cout << ans % mod << endl;
    return 0;
}