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

const double pi = acos(-1);
int n;
int q[2];
int p[101][2];
double le[101];
double le1[101];

inline double hu (int x1) {
    int x2 = x1 + 1,x3 = x1 - 1;
    if (x1 == n) x2 = 1;
    if (x1 == 1) x3 = n;
    double le1 = sqrt(pow(p[x1][0] - p[x2][0],2.0) + pow(p[x1][1] - p[x2][1],2.0));
    double le2 = sqrt(pow(p[x1][0] - p[x3][0], 2.0) + pow(p[x1][1] - p[x3][1], 2.0));
    double le3 = sqrt(pow(p[x3][0] - p[x2][0], 2.0) + pow(p[x3][1] - p[x2][1], 2.0));
    return pi - acos((le1*le1 + le2*le2 - le3*le3) / (2*le1*le2));
}

int main() {
    freopen("polygon.in", "r",stdin);
    freopen("polygon.out", "w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++) {
        scanf("%d%d",&p[i][0],&p[i][1]);
    }
    scanf("%d%d",&q[0],&q[1]);
    for (int i = 1;i <= n;i++) {
        le[i] = sqrt(pow(p[i][0] - q[0],2.0) + pow(p[i][1] - q[1],2.0));
    }
    double ans = 0.0;
    for(int i = 1;i <= n;i++) {
        ans += le[i] * hu(i);
    }
    printf("%.3f",ans);
    return 0;
}
/*
4
0 0
2 0
2 2
0 2
1 1

6
0 0
3 0
4 1
2 2
1 2
-1 1
1 0
*/