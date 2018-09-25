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

ull n = 1;
ull m, k;
ull ans;
ull sum[100000], cnt;

int main()
{
    cin >> k >> m;
    k %= m;
    ull last = 1;
    int n = 0;
    set<ull> e;
    while (!e.count(last))
    {
        sum[cnt + 1] = (last + sum[cnt]) % m;
        e.insert(last);
        last = (last * 10) % m;
        cnt++;
    }
    ull ans = 0x3f3f3f3f;
    for (int i = 1; i < cnt; i++)
    {
        // cout << m << ' ' << k << ' ' << sum[i] << ' ' << sum[cnt] << endl;
        if (sum[cnt])
        {
            if ((m + k - sum[i]) % sum[cnt] == 0)
                ans = min(ans, (m + k - sum[i]) / sum[cnt]);
        }
        else if (k - sum[i] == 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}