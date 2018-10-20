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

const int mod =  998244353 ;
ll l1, r1, l2, r2, m;

int main() {
    cin >> l1 >> r1 >> l2 >> r2 >> m;
    ll ans = 0;
    for(ll i = l1; i <= r1; i++)
        for (ll j = l2; j <= r2; j++)
            if (!((i^j)%m)) {
                ans++;
                if (ans >= mod) ans -= mod;
            }
    cout << ans << endl;
    return 0;
}