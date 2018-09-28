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

int ans = 0x3f3f3f3f;
int n, m, s, t;
int dis[101];
bool st[101];
int h[101], nx[1001], to[1001], c[1001], b[1001], e[1001], cnt;

inline void add(ci f, ci t, ci co, ci bg, ci ed) {
    nx[++cnt] = h[f]; 
    to[cnt] = t; 
    b[cnt] = bg;
    e[cnt] = ed;
    c[cnt] = co;
    h[f] = cnt; 
}

void spfa(int ex) {
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);
    dis[s] = ex;
    list<int> q;
    q.push_back(s);
    st[s] = 1;
    while(!q.empty()) {
        int x = q.front();
        // cout << x << endl;
        q.pop_front();
        st[x] = 0;
        for (int i = h[x]; i ; i = nx[i]) {
            if (max(dis[x], b[i]) + c[i] <= min(e[i], dis[to[i]])) {
                dis[to[i]] = max(dis[x], b[i]) + c[i];
                if (!st[to[i]]) {
                    q.push_back(to[i]);
                    st[to[i]] = 1;
                }
            }
        }
    }
    // cout << s << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << dis[i] << ' ';
    // cout << endl;
}

int main() {
    cin >> n >> m >> s >> t;
    int x, y, bg, ed, c1;
    int mn = 0x33f3f3f, mx = 0;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> bg >> ed >> c1;
        if (bg > ed) swap(bg, ed);
        if (ed - bg < c1) continue;
        add(x, y, c1, bg, ed);
        if (x == s) {
            mn = min(mn, bg);
            mx = max(mx, ed - c1);
        }
    }
    for (int i = mn; i <= mx; i++) {
        spfa(i);
        if (dis[t] == dis[0]) break;
        ans = min(ans, dis[t] - dis[s]);
    }
    if (ans < 0x3f3f3f) {
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }
    
    return 0;
}