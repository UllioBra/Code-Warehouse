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
double dis[1010];

struct stu {
    int x, y, w;
} arr[1010];

inline double dist (int x, int y) {
    return sqrt(pow(arr[x].x - arr[y].x, 2.0) + pow(arr[x].y - arr[y].y, 2.0));
}


bool check (double x) {
    memset(book, 0, sizeof book);
    book[1] = 1;
    double ans = 0;
    for (int i = 1; i <= n; i++)
        dis[i] = b[1][i] - x * a[1][i];
    for (int i = 1; i < n; i++) {
        int tmp;
        double mn = 1e9;
        for (int j = 1; j <= n; j++) {
            if (dis[j] < mn && !book[j]) {
                mn = dis[j];
                tmp = j;
            }
        }
        book[tmp] = 1;
        ans += mn;
        for (int j = 1; j <= n; j++)
            if (b[tmp][j] - x * a[tmp][j] < dis[j] && !book[j]) {
                dis[j] = b[tmp][j] - x * a[tmp][j];
            }
    }
    return ans >= 0;
}

int main() {
    while(scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].w);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j) {
                    a[j][i] = a[i][j] = dist(i, j);
                    b[j][i] = b[i][j] = abs(arr[i].w - arr[j].w);
                }
        double l = 0.0 , r = 100.0;
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