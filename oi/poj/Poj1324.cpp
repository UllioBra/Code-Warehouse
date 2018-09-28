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

int mv[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
int n, m, l, k;
bool mp[21][21];
int ans = 0x3f3f3f3f;

struct stu {
    int le;
    int body[9][2];
    void init(int l, int x_, int y_) {
        body[l][0] = x_;
        body[l][1] = y_;
    }
    bool move (ci x, ci y) {
        int a = body[1][0] + x;
        int b = body[1][1] + y;
        if (a < 1 || a > n) return false;
        if (b < 1 || b > m) return false;
        // cout << a << " -> " << b << endl;
        for (int i = le; i > 1; i--) {
            // cout << body[i][0] << " <- " << body[i][1] << endl;
            if (body[i][0] == a && body[i][1] == b)
                return false;
            body[i][0] = body[i-1][0];
            body[i][1] = body[i-1][1];
        }
        body[1][0] += x;
        body[1][1] += y;
        return true;
    }
}AC;

struct poi {
    int x, y, step;
    poi(int x_, int y_, int step_) {
        x = x_;
        y = y_;
        step = step_;
    }
};

int bfs(const stu & a) {
    // cout << 1 << endl;
    bool book[21][21];
    for (int i = 1; i <= a.le; i++) {
        // cout << a.body[i][0] << " < - > " << a.body[i][1] << endl;
        book[a.body[i][0]][a.body[i][1]] = 1;
    }
    list<poi> q;
    q.push_back((poi){a.body[1][0], a.body[1][1], 0});
    while(!q.empty()) {
        poi e = q.front();
        q.pop_front();
        if (e.x == 1 && e.y == 1) {
            return e.step;
        }
        for (int i = 0; i < 4 ; i++) {
            int x_ = e.x + mv[i][0];
            int y_ = e.y + mv[i][1];
            cout << x_ << " - - - " << y_ << endl;
            if (x_ < 1 || x_ > n) continue;
            if (y_ < 1 || y_ > m) continue;
            if (mp[x_][y_] || book[x_][y_]) continue;
            cout << x_ << " > - < " << y_ << endl;
            book[x_][y_] = 1;
            q.push_back((poi){x_, y_, e.step+1});
        }
    }
    return 0x3f3f3f3f;
}

bool check(const stu & a) {
    if (a.body[1][0] == 1 && a.body[1][1] == 1)
        return true;
    return false;
}

void dfs(const stu&a, int step, ci mn_dis) {
    // cout << step << endl;
    // cout << a.body[1][0] << '+' << a.body[1][1] << endl;
    if (step >= ans) return;
    if (check(a)) {
        ans = step;
        return;
    }
    for (int i =0; i < 4; i++) {
        stu tmp = a;
        if (tmp.move(mv[i][0], mv[i][1])) {
            int a1 = bfs(tmp);
            // cout << a1 << '-' << endl;
            if (mn_dis > a1)
                dfs(tmp, step + 1, a1);
        }
    }
}

int main() {
    int a, b;
    cin >> n >> m >> l;
    AC.le = l;
    for (int i = 1; i <= l; i++) {
        cin >> a >> b;
        AC.init(i, a, b);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        mp[a][b] = 1;
    }
    dfs(AC, 0, 0x3f3f3f3f);
    cout << ans << endl;
    return 0;
}