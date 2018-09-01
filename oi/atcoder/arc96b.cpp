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

const int le = 101000;
ll n, c;
ll sum_le[le], sum_ri[le];
ll dis_le[le], dis_ri[le];

int main() {
    scanf("%lld %lld", &n, &c);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld %lld", &dis_le[i], &sum_le[i]);
        dis_ri[n-i+1] = dis_le[i];
        sum_ri[n-i+1] = sum_le[i];
    }
    ll mx1 = sum_le[1] - dis_le[1];
    ll mx2 = sum_ri[1] - dis_ri[1];
    ll e1 = sum_le[1] - (dis_le[1] << 1);
    ll e2 = sum_ri[1] - (dis_ri[1] << 1);
    for (ll i = 2; i <= n; i++) {
        dis_le[i] += dis_le[i-1];
        dis_ri[i] += dis_ri[i-1];
        sum_le[i] += sum_le[i-1];
        sum_ri[i] += sum_ri[i-1];
        mx1 = max(mx1, sum_le[i]-dis_le[i]);
        mx2 = max(mx2, sum_ri[i]-dis_ri[i]);
        e1 = max(e1, sum_le[i] - (dis_le[i] << 1) );
        e2 = max(e2, sum_ri[i] - (dis_ri[i] << 1) );
    }
    if (e1 < 0) e1 = 0;
    if (e2 < 0) e2 = 0;
    ll ans = max(mx1 + e2, mx2 + e1);
    printf("%lld",ans);
    return 0;
}