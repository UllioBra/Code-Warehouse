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

const int le_ = 50050;
int n, m;
int arr[le_];
int le[le_][17], sum[le_][17];
int h[le_], nx[le_], to[le_], w[le_], cnt;
bool book[le_];
bool st[le_];
bool bk[le_];

struct stu {
    int id;
    int gen_le;
    int bel;
}brr[le_];

inline void add (int f, int t, int co) {
    nx[++cnt] = h[f]; h[f] = cnt; to[cnt] = t; w[cnt] = co;
    nx[++cnt] = h[t]; h[t] = cnt; to[cnt] = f; w[cnt] = co;
}

void dfs(int x) {
    brr[x].id = x;
    for (int i = h[x]; i; i = nx[i])
        if (to[i] != le[x][0]) {
            le[to[i]][0] = x;
            sum[to[i]][0] = w[i];
            brr[to[i]].gen_le = brr[x].gen_le + w[i];
            brr[to[i]].bel = brr[x].bel;
            dfs(to[i]);
        }
}

inline bool cmp1 (stu&a, stu&b) {
    return a.gen_le < b.gen_le;
}

bool dfs1(int x) {
    if (!nx[h[x]]) return false;
    bool e = 1;
    for (int i = h[x]; i; i = nx[i])
        if (!book[to[i]]) {
            e &= dfs1(to[i]);
        }
    return e;
}

inline bool check (ull x) {
    int ans = 0, l = 0, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if (brr[mid].gen_le >= x) {
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }
    for (int i = ans + 1; i <= n; i++) {
        int j = brr[i].gen_le;
        int k = brr[i].id;
        for (int l = 16; l >= 0; l--)
            if (sum[k][l] <= j && le[k][l] != 1) {
                j -= sum[k][l];
                k = le[k][l];
            }
        book[k] = 1;
    }
    for (int i = h[1]; i; i = nx[i]) {
        if (dfs1(i)) st[to[i]] = 1;
    }
    for (int i = ans; i >= 1; i++) {
        if (!st[brr[i].bel]) {
            st[brr[i].bel] = 1;
            bk[i] = 1;
        }
    }
    int e = h[1];
    for (int i = ans; i >= 1 && e; i++) {
        if(bk[i]) continue;
        while(e && st[e]) e = nx[e];
    }
}



int main() {
    int a, b, c;
    ull l = 0, r = 0, ans = -1;
    scanf("%d",&n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d" ,&a ,&b, &c);
        add(a, b, c);
        r += c;
    }
    scanf("%d",&m);
    for (int i = 1; i <= m; i++) {
        scanf("%d",&arr[i]);
    }
    brr[1].id = 1;
    for (int i = h[1]; i; i = nx[i]) {
        brr[to[i]].bel = to[i];
        le[to[i]][0] = 1;
        sum[to[i]][0] = w[i];
        brr[to[i]].gen_le = brr[1].gen_le + w[i];
        dfs(to[i]);
    }
    sort(brr + 1, brr + n + 1, cmp1);
    for (int i = 1; i <= 16; i++)
        for (int j = 1; j <= n; j++) {
            le[j][i] = le[le[j][i-1]][i-1];
            sum[j][i] = sum[sum[j][i-1]][i-1];
        }
    while (l < r) {
        ull mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    printf("%llu",ans);
    return 0;
}