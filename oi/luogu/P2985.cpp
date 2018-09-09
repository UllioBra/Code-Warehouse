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

int n,d;
int arr[500100];
int out[500100];

inline bool check (int x) {
    int i = 0;
    int tm = 1;
    ull tmp = 0 ;
    while (tm < d) {
        while (tmp < x && i < n) {
            tmp += arr[++i] ;
            out[i] = tm;
        }
        if (i == n) return false ;
        tm++;
        tmp >>= 1 ;
    }
    while (i < n) {
        tmp += arr[++i] ;
        out[i] = d ;
    }
    return tmp >= x;
}

int main() {
    ull l = 0, r = 0;
    scanf("%d %d",&n,&d);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&arr[i]);
        r += arr[i] ;
    }
    arr[n + 1] = 0; 
    ull mid = (l+r) >> 1;
    while(l <= r) {
        mid = (l+r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
        // printf("%d + %d \n", l, r);
    }
    // check(23);cout << endl;
    // check(l);
    printf("%lld\n", mid);
    for (int i = 1; i <= n; i++)
        printf("%d\n",out[i]);

    return 0;
}