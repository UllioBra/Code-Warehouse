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

int n;
int s[1<<21],dp[1<<21][2];


int main() {
    io_f;
    cin >> n;
    int r = 1 << n;
    for (int i = 0; i < r; i++) {
        cin >> s[i];
        dp[i][0] = i;
    }
    for (int i = 1; i < r; i++)
        for (int j = 0; (1<<j) <= r; j++)
            if (!(i & (1<<j))) {
                int tmp = i | (1<<j);
                if (s[dp[i][0]] > s[dp[tmp][0]]) {
                    dp[tmp][1] = dp[tmp][0];
                    dp[tmp][0] = dp[i][0];
                }else if (s[dp[i][0]] > s[dp[tmp][1]] && dp[i][0] != dp[tmp][1]) {
                    dp[tmp][1] = dp[i][0];
                }
                if (s[dp[i][1]] > s[dp[tmp][1]]) {
                    dp[tmp][1] = dp[i][1];
                }
            }
    int ans = 0;
    for (int i = 1; i < r; i++) {
        ans = max(ans, dp[i][0] + dp[i][1]);
        cout << ans << endl;
    }
    return 0;
}