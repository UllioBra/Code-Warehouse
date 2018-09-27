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

int k, n;
int sum[100100];
int w[20];
int dp[1<<17];
int f[1<<17];

int main() {
    int tot = 0;
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> w[i];
        tot += w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    int mx = (1 << k) - 1;
    for (int i = 0; i <= mx; i++) {
        for (int j = 0; (1 << j) <= i; j++) {
            if (i & (1 << j)) {
                int tmp = dp[i^(1<<j)];
                int st = upper_bound(sum + 1, sum + n + 1, sum[tmp]+w[j]) - sum;
                dp[i] = max(dp[i], st - 1);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= mx; i++) {
        if (dp[i] == n) {
            int num = 0;
            for (int j = 0; j < k; j++) {
                if (i & (1<<j)) {
                    num += w[j];
                }
            }
            ans = max(ans, tot - num);
        }
    }
    cout << ans;
    return 0;
}