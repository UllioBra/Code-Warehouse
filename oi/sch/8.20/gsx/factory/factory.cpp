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

const long long inf = 999999999999ll;
int n,k;
int h[100100],nx[100100],to[100100],w[100100],dep[100100],cnt;
int fa[100100],tr[100100],r[100100];
ll dp[101][100001];

inline void add (ci f,ci t,ci co) {
    nx[++cnt] = h[f];h[f] = cnt;to[cnt] = t;w[cnt] = co;dep[t]++;
    nx[++cnt] = h[t];h[t] = cnt;to[cnt] = f;w[cnt] = co;dep[f]++;
}

void dfs(ci id) {
    bool st = 0;
    for (int i = h[id];i;i = nx[i])
        if (to[i] != fa[id]) {
            fa[to[i]] = id;
            r[to[i]] = w[i];
            dfs(to[i]);
            st = 1;
            tr[id] += tr[to[i]];
        }
    if (st == 0) tr[id] = 1,dp[id][1] = 0;
    for (int kk = k - 1;kk >= 0;kk--)
        for (int j = 1;j <= tr[id];j++)
            if (j + kk <= k && dp[fa[id]][kk] < inf) 
            {
                if(dp[id][j] <inf)
                    dp[fa[id]][j+kk] = min(dp[fa[id]][j+kk],dp[fa[id]][kk] + (k-j)*r[id] + dp[id][j]);
            } else break;      
}

int main() {
    freopen("factory.in", "r",stdin);
    freopen("factory.out", "w",stdout);
    cin>>n>>k;
    int a,b,c;
    if (k == 1) {
        cout<<0;
        return 0;
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= k;j++)
            dp[i][j] = inf;
    for (int i = 1;i < n;i++) {
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int se = 0;
    for(int i = 1;i <= n;i++) {
        if (dep[i] >= 2) se = i;
        break;
    }    
    dfs(se);
    cout<<dp[se][k];
    return 0;
}
/*
4 3
1 2 2
1 3 3
1 4 4
*/