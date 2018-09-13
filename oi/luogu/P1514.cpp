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

bool book[505][505];
int n, m, cnt, num;
int mp[505][505];
int l[505][505], r[505][505];
int mv[4][2] = {
    {0, 1},{1, 0},{0, -1},{-1, 0}
} ;

struct stu {
    int l, r;
    stu() {
        l = 0x3f3f3f3f;
    }
    bool operator < (const stu&a)const {
        if (l == a.l) return r < a.r;
        return l < a.l;
    }
} arr[505];

void dfs(int x, int y) {
    book[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int lx = x + mv[i][0];
        int ly = y + mv[i][1];
        if (lx < 1 || lx > n) continue;
        if (ly < 1 || ly > m) continue;
        if (mp[x][y] <= mp[lx][ly]) continue;
        if (!book[lx][ly]) dfs(lx, ly);
        l[x][y] = min(l[x][y], l[lx][ly]);
        r[x][y] = max(r[lx][ly], r[x][y]);
    }
}

int main() {
    cin >> n >> m;
    memset(l, 0x3f, sizeof l);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= m; i++) {
        l[n][i] = r[n][i] = i;
    }
    for (int i = 1; i <= m; i++)
        if (!book[1][i]) {
            dfs(1, i);
        }
    for (int i = 1; i <= m; i++)
        if (book[n][i]) {
            num++;
        }
    // cout << num << endl;
    if (num != m) {
        cout << 0 << endl << m - num << endl;
        return 0;
    }
    int le = 1, ans = 0;
    while (le <= m) {
        int mx = 0;
        for (int i = 1; i <= m; i++)
            if (l[1][i] <= le) mx = max(mx, r[1][i]);
        ans++;
        le = mx + 1;
    }
    cout << 1 << endl << ans << endl;

    return 0;
} 