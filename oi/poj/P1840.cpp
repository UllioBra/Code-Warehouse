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
#define lson (id << 1)
#define rson (id << 1)+1
#define ll long long
#define ull unsigned long long
#define ci const int&
#define cl const long long&
#define cul const unsigned long long&
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

int n, m;

int sum[200002 << 2];

void insert(ci l, ci r, ci L, ci R, ci id) {
    // cout << l << ' ' << r << ' ' << L << ' ' << R << ' ' << id << endl;
    if (l >= L && r <= R) {
        sum[id] = r - l + 1;
        return;
    }
    int mid = (l+r) >> 1;
    if (L <= mid) insert(l, mid, L, R, lson);
    if (R >= mid + 1) insert(mid + 1, r, L, R, rson);
    sum[id] = max(sum[lson] + sum[rson], sum[id]);
}

int main() {
    int a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        insert(1, n, a, b, 1);
        cout << n - sum[1] << endl;
    }
    return 0;
}