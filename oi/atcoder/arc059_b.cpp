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

string a;

int main() {
    cin >> a;
    int le = a.size();
    for (int i = 0; i < le - 1; i++) {
        if (a[i] == a[i+1]) {
            cout << i+1 << ' ' << i+2 << endl;
            return 0;
        } else if (a[i] == a[i+2] && i != le - 2) {
            cout << i+1 << ' ' << i+3 << endl;
            return 0;
        }
    }
    cout << -1 << ' ' << -1 << endl;
    return 0;
}