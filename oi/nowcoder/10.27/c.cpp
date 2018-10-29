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
#define ci const int &
#define cl const long long &
#define cul const unsigned long long &
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

int n;
ll a[101000];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    ll ans = 0;
    while (l < r) {
        if (l + 1 == r)
        {
            ans += a[r] - a[l];
        }
        else
        {
            ans += a[r] + a[r - 1] - (a[l] << 1);
        }
        l++;
        r--;
    }
    l = 1, r = n;
    ll ans1 = 0;
    while(l < r) {
        if(l + 1 == r) {
            ans += a[r] - a[l];
        } else {
            ans += (a[r]<<1) - a[l] - a[l+1];
        }
        l++;r--;
    }
    printf("%lld",max(ans,ans1));
    return 0;
}