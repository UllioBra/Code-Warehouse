#include <algorithm>
#include <cstring>
#include <iostream>
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

char b[500500];

int main() {
    char a[30];
    int le = 0;
    int le_;
    while(cin >> a && (le_ = strlen(a))) {
        bool st = 0;
        for(int i = 0; i < le_; i++) {
            if (a[i] == 'E') {
                st = 1;
                break;
            }
            b[le++] = a[i];
        }
        if (st) {
            break;
        }
    }
    cout << le;
    for (int i = 0; i < le; i ++) {
        cout << b[i];
    }
    return 0;
}