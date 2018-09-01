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

int a1,b1,a2,b2;

int main() {
    cin >> a1 >> b1 >> a2 >> b2;
    int l1 = a1 - a2;
    int l2 = b1 - b2;
    int a3 = a2 + l2, b3 = b2 - l1;
    cout << a3 << ' ' << b3 << ' ';
    cout << a3 + b2 - b3  << ' ' << b3 - a2 + a3;
    return 0;
}