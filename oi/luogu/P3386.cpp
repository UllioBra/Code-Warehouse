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

const int s = 2001,t = 2002;
const int bs = 1000;
const int mx_n = 2010;
const int mx_e = 2000000;
const int inf = 0x3f3f3f3f;
int h[mx_n],nx[mx_e],to[mx_e],w[mx_e],cnt;
int dis[mx_n];
 
inline void add(const int&f,const int&t,const int&co) {
   nx[cnt] = h[f]; h[f] = cnt; to[cnt] = t; w[cnt++] = co;
   nx[cnt] = h[t]; h[t] = cnt; to[cnt] = f; w[cnt++] = co;
}
 
int n,m,e,ans;

inline bool bfs() {
    list<int> e;
    e.push_back(s);
    memset(dis,0,sizeof dis);
    dis[s] = 1;
    int q;
    while(!e.empty()) {
        q = e.front();
        e.pop_front();
        for(int i = h[q]; i >= 0; i = nx[i])
            if(w[i] && !dis[to[i]]) {
                dis[to[i]] = dis[q] + 1;
                e.push_back(to[i]);
            }
    }
    return dis[t] != 0;
}

inline int dfs(int id,int cap) {
    if(id == t) return cap;
    int d,now = cap;
    for(int i = h[id]; i >= 0; i = nx[i])
        if(w[i] && dis[to[i]] == dis[id] + 1) {
            d = dfs(to[i],min(cap,w[i]));
            if(now >= d) {
                w[i] -= d;
                w[i^1] += d;
                now -= d;
            }
            if(!now) break;
        }
    return cap - now;
}

inline void dinic() {
    int mx_f = 0;
    while(bfs()) {
        mx_f += dfs(s,inf);
    }
    printf("%d",mx_f);
}

int main() {
    // freopen("1.in","r",stdin);
    int u,v;
    memset(h,-1,sizeof h);
    scanf("%d%d%d",&n,&m,&e);
    for(int i = 1; i <= e; i++) {scanf("%d%d",&u,&v);if(v <= m && u <= n && u >= 1 && v >= 1) add(u,v+bs,1);}
    for(int i = 1; i <= n; i++) add(s,i,1);
    for(int i = 1; i <= m; i++) add(t,i+bs,1);
    dinic();
}