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

<<<<<<< HEAD
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
=======
bool book[5050];
bool mp[5005][5005];
int n, m;
int ans = 0x3f3f3f3f;
int arr[5050];
int brr[5050];

void dfs(const int &lim, int id, int k)
{
    cout << lim << '+' << id << '+' << k << endl;
    if (k >= ans)
        return;
    if (k % 2)
    {
        for (int i = 1; i <= n; i++)
            if (!book[i] && mp[id][i])
            {
                mp[id][i] = 0;
                arr[k + 1] = i;
                book[i] = 1;
                dfs(lim, i, k + 1);
                book[i] = 0;
                mp[id][i] = 1;
            }
    }
    else
    {
        if (mp[lim][id])
        {
            ans = min(ans, k);
            for (int i = 1; i <= ans; i++)
                brr[i] = arr[i];
            return;
        }
        for (int i = 1; i <= n; i++)
            if (!book[i] && mp[i][id])
            {
                mp[i][id] = 0;
                arr[k + 1] = i;
                book[i] = 1;
                dfs(lim, i, k + 1);
                book[i] = 0;
                mp[i][id] = 1;
            }
    }
}

int main()
{
    int a, b;
    cin >> a;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        mp[a][b] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        arr[1] = i;
        dfs(i, i, 1);
    }
    if (ans > n)
        ans = -1;
    cout << ans << endl;
    for (int i = 1; i <= ans; i++)
        cout << brr[i] << ' ';
>>>>>>> 3bd4892c97b8dd51503eb33a3d7168749bd234b9
    return 0;
}