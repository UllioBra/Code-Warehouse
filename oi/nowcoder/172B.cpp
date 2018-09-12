#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <set>
#define ull long long
#define io_F std::ios::sync_with_stdio(false)
using namespace std;

const int bs = 80127;
int cnt;
map<ull, ull> dp[20];
ull L, R, L1, R1;
ull mp[21];

ull dfs(int l, ull pr, int lim)
{
    if (l == 0)
    {
        if (pr == -1)
            pr = 0;
        return (pr >= L1 && pr <= R1);
    }
    if (!lim && pr >= 0 && dp[l].count(pr))
        return dp[l][pr];
    ull mx = 9;
    if (lim)
        mx = min(mx, mp[l]);
    ull tmp = 0;
    for (ull i = 0; i <= mx; i++)
    {
        if (pr == -1)
        {
            if (i == 0)
                tmp += dfs(l - 1, pr, lim && (i == mx));
            else
                tmp += dfs(l - 1, i, lim && (i == mx));
        }
        else
        {
            tmp += dfs(l - 1, pr * i, lim && (i == mx));
        }
    }
    if (!lim && pr >= 0)
        dp[l][pr] = tmp;
    return tmp;
}

inline ull deal(ull x)
{
    if (x < 0)
        return 0;
    int le = 0;
    while (x)
    {
        mp[++le] = x % 10;
        x /= 10;
    }
    return dfs(le, -1, 1);
}

int main()
{
    cin >> L >> R >> L1 >> R1;
    cout << deal(R) - deal(L - 1) << endl;
    return 0;
}