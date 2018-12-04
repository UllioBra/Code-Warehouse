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

int n,m,w1,x,y;
int dp[1010],f[1010],co[1010],ct;
int w[1010],b[1010],bcj[1010],id[1010];

int f_(int x) {return bcj[x] == x ? x : bcj[x] = f_(bcj[x]);}

void s(int &x,int &y) {if(x < y) swap(x,y);}

int main() {
    scanf("%d%d%d",&n,&m,&w1);
    for(int i = 1; i <= n; i++) bcj[i] = i;
    for(int i = 1; i <= n; i++) scanf("%d",&w[i]);
    for(int i = 1; i <= n; i++) scanf("%d",&b[i]);
    for(int i = 1; i <= m; i++) scanf("%d%d",&x,&y),s(x,y),bcj[f_(x)] = f_(y);
    for(int i = 1; i <= n; i++) {
         if(bcj[i] == i) f[++ct] += b[i],co[ct] += w[i],id[i] = ct;
         else f[id[f_(i)]] += b[i],co[id[f_(i)]] += w[i];
    } dp[0] = 1;
    for(int i = 1; i <= ct; i++)
        for(int j = w1; j >= 0; j--) {
            for(int k = 1; k <= n; k++)
                if(id[f_(k)] == i && j >= w[k] && dp[j-w[k]]) {
                        dp[j] = max(dp[j],dp[j-w[k]]+b[k]);
                    }
            if((j >= co[i] && dp[j-co[i]])) dp[j] = max(dp[j],dp[j-co[i]]+f[i]);
        }
    int ans = 0;
    for(int i = 0; i <= w1; i++) ans = max(ans,dp[i]);
    printf("%d",ans-1);
    return 0;
}