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

int n;
int sum1, sum2;
int arr[100100];
int brr[100100];

inline int get (int x) {
    int a = (sum2 - (n*arr[x]-sum1)*(n*arr[x]-sum1) ) / n;
    int b = (sum2 - (n*arr[x]-sum1)*(n*arr[x]-sum1) ) / (n*n);
    // cout << a << '+' << b << endl;
    return a - b;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum1 += arr[i];
    }
    for (int i = 1; i <= n; i++) {
        sum2 += (int)pow(n * arr[i] - sum1, 2.0);
    }
    for (int i = 1; i <= n; i++) {
        if (i != n)cout << get(i) << ' ';
        else cout << get(i) << endl;
    }

    return 0;
}