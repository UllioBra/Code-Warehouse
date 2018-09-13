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

const double eps = 1e-4;
int n;
double mid;
double a[1010][1010];
int b[1010][1010];
bool book[1010];

struct stu {
    int x, y, w;
} arr[1010];

struct edge {
    int t;
    double w;
};

inline double dis (int x, int y) {
    return sqrt(pow(arr[x].x - arr[y].x, 2.0) + pow(arr[x].y - arr[y].y, 2.0));
}

struct cmp {
    bool operator () (const stu&a, const stu&b) {
        return a.w < b.w ;
    }
    bool operator () (const edge&a, const edge&b) {
        return a.w > b.w ;
    }
};

bool check (double x) {
    

    // memset(book, 0, sizeof book);
    // book[1] = 1;
    // priority_queue<edge, vector<edge>, cmp> e;
    // for (int i = 2; i <= n; i++) {
    //     e.push((edge){i, (double)b[1][i] - x * a[1][i]});
    // }
    // int num = 0;
    // double ans = 0.0;
    // while(num < n && !e.empty()) {
    //     edge q = e.top();
    //     e.pop();
    //     if (book[q.t]) continue;
    //     book[q.t] = 1;
    //     ans += q.w;
    //     num++;
    //     for (int i = 1; i <= n; i++)
    //         if (i != q.t) {
    //             if (!book[i]) {
    //                 e.push((edge){i, (double)b[q.t][i] - x * a[q.t][i]});
    //             }
    //         }
    // }
    // return ans >= 0;
}

int main() {
    while(scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].w);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j) {
                    a[j][i] = a[i][j] = dis(i, j);
                    b[j][i] = b[i][j] = abs(arr[i].w - arr[j].w);
                }
        double l = 0.0 , r = 1000.0;
        while (r - l > eps) {
            mid = (l + r) / 2.0;
            if(check(mid)) {
                l = mid;
            } else r = mid;
        }
        printf("%.3f\n",l);
    }

    return 0;
}