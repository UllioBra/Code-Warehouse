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

int n, m;
int mp[5050][5050];
int dis[5050];
bool book[5050];

int main() {
    int a, b, c;
    cin >> n >> m;
    memset(mp, 0x3f, sizeof mp);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        mp[a][b] = min(mp[a][b], c);
        mp[b][a] = mp[a][b];
    }
    book[1] = 1;
    for (int i = 2; i <= n; i++)
        dis[i] = mp[1][i];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int mn = 0x3f3f3f3f;
        int tmp ;
        for (int j = 1; j <= n; j++)
            if (dis[j] < mn && !book[j]) {
                mn = dis[j];
                tmp = j;
            }
        for (int j = 1; j <= n; j++)
            if (j != tmp && !book[j]) {
                dis[j] = min(dis[j], mp[tmp][j]);
            }
        book[tmp] = 1;
        ans += mn;
    }
    cout << ans << endl;
    return 0;
}