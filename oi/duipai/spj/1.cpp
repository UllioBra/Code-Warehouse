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

bool mp[5005][5005];
int n, m;
int ans;
int brr[5050];

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
    cin >> ans;
    if (ans % 2)
    {
        cout << -1;
        return 0;
    }
    if (ans == 'a')
    {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= ans; i++)
        cin >> brr[i];
    if (!mp[brr[1]][brr[ans]])
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i < n; i++)
        if (i % 2 && !mp[brr[i]][brr[i + 1]])
        {
            cout << -1;
            return 0;
        }
        else if (!(i % 2) && !mp[brr[i + 1]][brr[i]])
        {
            cout << -1;
            return 0;
        }
    return 0;
}