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

const int mod = 1000000007;
string a;
int le;
int dp[2][2][100][10];


int main() {
    cin>>a;
    le = a.size();
    // for (int i = 2;i <= le;i++)
    // {
    //     for (int j = 1;j <= 9;j++)
    //     {
    //         dp[0][0][i][j] = 1;
    //     }
    // }
    for (int i = 1;i <= le;i++) 
    {
        if (i == 1) {
            for (int j = 0;j < a[0] - '0';j++) 
            {
                dp[0][0][i][j] = 1;
                // dp[1][0][i][j] = 1;
            }
            dp[0][1][i][a[0] - '0'] = 1;
            // dp[1][1][i][a[0] - '0'] = 1;
        } else {
            for (int j = 0;j <= 9;j++)
            {
                for (int jj = j;jj <= 9;jj++) dp[0][0][i][j] += dp[0][0][i-1][jj];
                for (int jj = 0;jj < j;jj++) dp[1][0][i][j] += dp[0][0][i-1][jj];
                for (int jj = 0;jj <= j;jj++) dp[1][0][i][j] += dp[1][0][i-1][jj];
                if (j < a[i-1] - '0' && j <= a[i-2] - '0') dp[0][0][i][j] += dp[0][1][i-1][a[i-2] - '0'];
                if (j < a[i-1] - '0' && j > a[i-2] - '0') dp[1][0][i][j] += dp[0][1][i-1][a[i-2] - '0'];
                if (j < a[i-1] - '0' && j >= a[i-2] - '0') dp[1][0][i][j] += dp[1][1][i-1][a[i-2] - '0'];
                if (a[i-1] <= a[i-2]) dp[0][1][i][a[i-1] - '0'] += dp[0][1][i-1][a[i-2] - '0'];
                if (a[i-2] <= a[i-1]) dp[1][1][i][a[i-1] - '0'] += dp[1][1][i-1][a[i-2] - '0'];
            }
        }
    }
    ll ans = 0;
    for (int i = 0;i <= 9;i++) ans += dp[0][0][le][i] + dp[1][0][le][i];
    ans += dp[0][1][le][a[le-1] - '0'] + dp[1][0][le][a[le-1] - '0'];
    cout<<ans<<endl;
    return 0;
}