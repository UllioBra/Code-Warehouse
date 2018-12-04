#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>
 
#define ll long long
#define ull unsigned long long
 
using namespace std;

const int bs = 1000;
const int mx_n = 20000;
const int mx_e = 2000000;
int h[mx_n],nx[mx_e],to[mx_e],cnt;
bool vis[20020];
int bel[20020];
 
inline void add(const int&f,const int&t) {
   nx[++cnt] = h[f]; h[f] = cnt; to[cnt] = t;
   nx[++cnt] = h[t]; h[t] = cnt; to[cnt] = f;
}
 
int n,m,e,ans;

bool dfs(int x) {
    for(int i = h[x]; i; i = nx[i]) if(!vis[to[i]]) {
        vis[to[i]] = 1;
        if(!bel[to[i]] || dfs(bel[to[i]])) {
            bel[to[i]] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    // freopen("1.in","r",stdin);
    int u,v;
    scanf("%d%d%d",&n,&m,&e);
    for(int i = 1; i <= e; i++) {scanf("%d%d",&u,&v);if(v <= m && u <= n && u >= 1 && v >= 1) add(u,v+bs);}
    for(int i = 1; i <= n; i++) memset(vis,0,sizeof vis),ans += dfs(i); 
    printf("%d",ans);       
}