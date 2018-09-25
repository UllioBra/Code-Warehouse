// luogu-judger-enable-o2
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
#define ci const int &
#define cl const long long &
#define cul const unsigned long long &
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

ull n = 1;
ull m, k;
ull ans;

int main()
{
    cin >> k >> m;
    k %= m;
    ull sum = 1;
    ull last = 1;
    int n = 1;
    while (sum < k || (sum - k) % m != 0)
    {
        sum %= m;
        last = (last * 10) % m;
        sum += last;
        n++;
        // cout << n << ' ' << last << ' ' << sum << endl;
    }
    cout << n;
    return 0;
}