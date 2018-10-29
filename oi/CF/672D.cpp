#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>

#define ll long long
#define ull unsigned long long

using namespace std;

int n;
ull k;
ull a[505000];

bool check(ull x) {
//    cout << x << '+' << endl;
    ull sum = 0;
    for(int i = n; i >= 1; i--)
        if(a[i] > x) sum += a[i] - x;
//    cout << sum << "-" << endl;
    return sum <= k;
}

bool check1(ull x) {
    ll sum = k;
    for(int i = 1; i <= n; i++) {
//    	cout << x << '&' << a[i] << endl;
        sum -= (x - a[i]);
        if(sum < 0) return false;
    }
    return true;
}

int main() {
    scanf("%d%llu",&n,&k);
    for(int i = 1; i <= n; i++) {
        scanf("%llu",&a[i]);
    }
    sort(a+1,a+1+n);
    ull l = a[1], r = a[n], ans;
    while(l <= r) {
        ull mid = (l+r) >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    l = a[1], r = a[n];
    ull ans1;
    while(l <= r) {
        ull mid = (l+r) >> 1;
        if(check1(mid)) {
            l = mid + 1;
            ans1 = mid;
        } else r = mid - 1;
    }
    printf("%llu\n",ans-ans1);
}