#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <set>
#define ll long long
#define ull unsigned long long
#define io_F std::ios::sync_with_stdio(false)
using namespace std;

const int bs = 80127;
int cnt;
map<ull, int> e;
string L, R;
ull L1, R1;
ull num[20][100000];
ull mp[100000];

void dfs(ull x) {
    if (x > 1e18) return;
    cout << x << endl;
    for (ull i = 2; i <= 9; i++)
        if (!e.count(x*i)) {
            e.insert(pair<ull, int>(x*i, ++cnt));
            mp[cnt] = x * i;
            dfs(x*i);
        }
}

int main () {
    cin >> L >> R >> L1 >> R1;
    dfs(1);
    cout << cnt << endl;
    e.insert(pair<ull, int>(0, 0));
    int le1 = L.size(), le2 = R.size();
    num[0][1] = 1;
    for (int i = 0; i < 20; i++)
        for (int j = 1; j <= bs; j++)
            if (num[i][j]) {
                for (ull k = 0; k <= 9; k++) 
                    num[i+1][e[mp[j]*k]] += num[i][j];
            }
    for (int i = 0; i < 20; i++)
        for (int j = 1; j <= bs; j++) 
            if (j == bs) cout << num[i][j] << endl;
            else cout << num[i][j] << ' ';
    map<ull, int>::iterator it1,it2;
    ull tmp = 1;
    ull ans = 0;
    ull l1 = L1, r1 = R1;
    for (int i = 0; i < le1; i++) {
        for (int j = L[i] - '0' - 1; j >=0; j--) {
            it1 = e.lower_bound();
            it2 = e.lower_bound(r1);

        }
        tmp *= L[i] - '0';
    }
    return 0;
}