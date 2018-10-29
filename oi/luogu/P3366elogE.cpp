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

int n, m, ans;
bool book[5050];
int h[5050], nx[400200], to[400200], w[400200], cnt;

struct stu {
    int t;
    int w;
    // bool operator < (const stu&a)const{ 
    //     return w < a.w ; 
    // }
};

struct cmp {
    bool operator () (const stu&a, const stu&b) {
        return a.w > b.w ;
    }
};

inline void add (int f, int t, int co) {
    nx[++cnt] = h[f]; h[f] = cnt; to[cnt] = t; w[cnt] = co;
    nx[++cnt] = h[t]; h[t] = cnt; to[cnt] = f; w[cnt] = co;
}

void Prim () {
    book[1] = 1;
    priority_queue<stu, vector<stu>, cmp> e;
    for (int i = h[1]; i; i = nx[i]) {
        e.push((stu){to[i], w[i]});
    }
    int num = 1;
    while(num < n && !e.empty()) {
        stu q = e.top();
        // cout << q.t << ' ' << q.w << endl;
        e.pop();
        if (book[q.t]) continue;
        book[q.t] = 1;
        ans += q.w;
        num++;
        for (int i = h[q.t]; i; i = nx[i])
            if (!book[to[i]]) {
                e.push((stu){to[i], w[i]});
            }
    }
    printf("%d",ans);
}

int main() {
    int a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        add(a,b,c);
    }
    Prim();
    return 0;
}