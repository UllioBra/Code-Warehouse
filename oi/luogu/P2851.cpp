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

int t, n;
int h[10100];
int dp[20100];
struct stu {
    int num;
    int val;
    bool operator < (const stu & a) const {
        return val > a.val;
    }
}arr[101];

int main() {
    cin >> n >> t;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].val;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].num;
        sum += arr[i].num * arr[i].val;
    }
    if (sum < t) {
        cout << -1;
        return 0;
    }
    sort(arr + 1, arr + 1 + n);
    memset(h, -1, sizeof h);
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    h[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= t-arr[i].val; j++)
            if (h[j] >= 0) {
                if (h[j+arr[i].val] < 0 || h[j+arr[i].val] > h[j] + 1)
                    h[j+arr[i].val] = h[j] + 1;
            }
    // for (int i = 1; i <= n; i++)
    //     cout << arr[i].val << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 15; j++)
            if (arr[i].num >= (1 << j)) {
                arr[i].num -= (1 << j);
                int tmp = arr[i].val * (1 << j);
                for (int k = 2*t; k >= tmp; k--)
                    if (dp[k-tmp] >= 0) {
                        if (dp[k] < 0 || dp[k-tmp] + (1 << j) < dp[k]) {
                            dp[k] = dp[k-tmp] + (1 << j);
                        }
                    }
            }
        if (arr[i].num == 0)continue;
        int tmp = arr[i].num * arr[i].val;
        for (int k = 2*t; k >= tmp; k--)
            if (dp[k-tmp] >= 0) {
                if (dp[k] < 0 || dp[k-tmp] + arr[i].num < dp[k]) {
                    dp[k] = dp[k-tmp] + arr[i].num;
                }
            }
    }
    int ans = -1;
    for (int i = 0; i <= t; i++)
        if (dp[t+i] >= 0 && h[i] >= 0)
            if (ans == -1 || dp[t+i] + h[i] < ans)
                ans = dp[t+i] + h[i];
    
    cout << ans << endl;
    return 0;
}