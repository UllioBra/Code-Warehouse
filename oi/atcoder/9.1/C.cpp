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

int n,k;

int main() {
    cin >> n >> k;
    if (k % 2) {
        cout << (ll)pow((ll)(n/k),3.0);
    } else {
        ll ans = (ll)pow((ll)((n+k/2)/k),3.0);
        cout << (ll)pow((ll)(n/k),3.0) + ans;
    }
    return 0;
}