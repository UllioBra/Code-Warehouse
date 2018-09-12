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

int n, le;
int arr[100100];
int brr[100100];
int crr[100100];

inline bool check (int x) {
    int mn = 0x3f3f3f3f, mx = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        crr[i] = crr[i-1] + (brr[i] < x ? -1 : 1) ;
        // cout << crr[i] << "+" << i << endl;
        if (i >= le) {
            mn = min(mn, crr[i-le]);
            mx = crr[i];
            // cout << mn << ' ' << mx << ' ' << x << endl;
            if (mx - mn > 0) return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &le);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&arr[i]);
        brr[i] = arr[i];
    }
    int l = 1, r = n, ans ;
    sort(arr + 1, arr + n + 1);
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (check(arr[mid])) {
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }
    printf("%d", arr[ans]);

    return 0;
}