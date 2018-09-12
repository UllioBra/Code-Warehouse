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

const double eps = 1e-7;
int n, k;
ull a[1010], b[1010];
double d[1010];

inline bool check (double x) {
    for (int i = 1; i <= n; i++) {
        d[i] = a[i] - x * b[i];
    }
    sort(d + 1, d + n + 1);
    double tmp = 0.0;
    for (int i = k + 1; i <= n; i++)
        tmp += d[i];
    return tmp > 0;
}

int main() {
    while(~scanf("%d %d", &n, &k) && (n||k)) {
        for (int i = 1; i <= n; i++)
            scanf("%llu", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%llu", &b[i]);
        double l = 0.0, r = 100.0, ans = 0.0;
        while (r - l > eps) {
            // cout << l << ' ' << r << endl;
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else r = mid;
        }
        printf("%d\n",int(100*l+0.5));
    }
    return 0;
}