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

const int mod = 1e9 + 7;
int n;
int arr[50500];
int idx[50500];

struct stu {
    int le, sum;
    stu() {
        le = 0;
        sum = 0;
    }
} brr[50500];

inline bool cmp (ci idx, ci idy) {
    return arr[idx] == arr[idy] ? idx > idy : arr[idx] < arr[idy];
}

void Max(stu & a, stu b) {
    if (a.le < b.le) a = b;
    else if (a.le == b.le) {
        if ((a.sum += b.sum) >= mod) {
            a.sum -= mod;
        }
    }
}

void cdq(ci l, ci r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    for (int i = l; i <= r; i++) {
        idx[i] = i;
    }
    sort(idx + l, idx + r + 1, cmp);
    
    stu mx;

    for (int i = l; i <= r; i++) {
        int id = idx[i];
        if (id <= mid) {
            Max(mx, brr[id]);
        } else {
            stu tmp = mx;
            tmp.le++;
            Max(brr[id], tmp);
        }
    }
    cdq(mid+1 , r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        brr[i].le = 1;
        brr[i].sum = 1;
        cin >> arr[i];
    }
    cdq(1, n);
    stu ans;
    for (int i = 1; i <= n; i++) {
        Max(ans, brr[i]);
    }
    cout << ans.sum << endl;
    return 0;
}