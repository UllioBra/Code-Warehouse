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

int n,m;
ll p;
ll a[40];
int book[1000000],cnt = 1;
vector<int> e[40];

int main() {
    cin>>n>>m>>p;
    for (int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    int c1,c2;
    for (int i = 1;i <= m;i++) {
        cin>>c1>>c2;
        e[c1].push_back(i);
        e[c2].push_back(i);
    }
    ll ans = 0;
    for (ll i = 1;i <= (1<<n) - 1;i++) {
        int tmp = 0;
        ll sum = 1;

        for (ll j = 0;(1 << j) <= i;j++) {
            if ((1 << j) & i) {
                sum *= a[j+1];
                if (sum >= p) sum %= p;
                for (int k = 0;k < e[j+1].size();k++)
                {
                    if(book[e[j+1][k]] < cnt) 
                    {
                        book[e[j+1][k]] = cnt;
                        tmp++;
                    }
                }
            }
        }

        ++cnt;
        if (tmp == m) 
        {
            ans += sum;
            if (ans >= p) ans %= p;
        }
    }
    cout<<ans<<endl;
    return 0;
}