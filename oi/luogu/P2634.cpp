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

const int inf = 0x3f3f3f3f;
const int mx = 21000;
int n,m,sum;
int h[mx],nx[mx<<1],to[mx<<1];
ull w[mx<<1],cnt;
ull ans;

inline void add(int f,int t,int co) {
    nx[++cnt] = h[f]; h[f] = cnt; to[cnt] = t; w[cnt] = co;
    nx[++cnt] = h[t]; h[t] = cnt; to[cnt] = f; w[cnt] = co;
}

ull rem[3],ct;
ull rt,maxs[mx],siz[mx],dis[mx],is_dis[3];
bool vis[mx];
bool mp[mx];

inline void getrt(int x,int fa) {
    siz[x] = 1;maxs[x] = 0;
    for(int i = h[x]; i; i = nx[i])
        if(to[i] != fa && !vis[to[i]]) {
            getrt(to[i],x);
            siz[x] += siz[to[i]];
            maxs[x] = max(maxs[x],siz[to[i]]);
        }
    maxs[x] = max(maxs[x],sum-siz[x]);
    if(maxs[x] < maxs[rt]) rt = x;
}

inline void getdis(int x,int fa) {
    rem[dis[x]]++;
    for(int i = h[x]; i; i = nx[i])
        if(to[i] != fa && !vis[to[i]]) {
            dis[to[i]] = (dis[x] + w[i]) % 3;
            getdis(to[i],x);
        }
}

inline void calc(int x) {
    for(int i = h[x]; i; i = nx[i])
        if(!vis[to[i]]) {
            dis[to[i]] = w[i] % 3;
            getdis(to[i],x);

            for(int j = 0; j < 3; j++) {
                ans += rem[j] * is_dis[(3-j) % 3] * 2;
            }
            
            for(int j = 0; j < 3; j++)
                is_dis[j] += rem[j],rem[j] = 0;
        }
    // cout << x << '+' << endl;
    // for(int i = 0; i < 3; i++)
    //     cout << is_dis[i] << endl;
    for(int i = 0; i < 3; i++)
        is_dis[i] = 0;
}

inline void deal(int x) {
    vis[x] = (is_dis[0] = 1); 
    
    // cout<<x<<endl;
    calc(x);
    // cout<<ans<<endl;

    for(int i = h[x]; i; i = nx[i])
        if(!vis[to[i]]) {
            sum = siz[to[i]];
            maxs[rt=0] = n;
            getrt(to[i],0);

            deal(rt);
        }
}

ll gcd(ll x,ll y) {
    return y == 0 ? x : gcd(y,x%y);
}

int main() {
    // freopen("1.in","r",stdin);
    int a,b,c;
    scanf("%d",&n);
    for(int i = 1; i < n; i++) {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }

    maxs[rt] = sum = n;
    getrt(1,0);
    deal(rt);
    ans += n;
    ll x = gcd(n*n,ans);
    printf("%lld/%lld",ans/x,(ll)(n*n/x));
}