#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <list>
#include <map>

#define lson (id<<1)
#define rson ((id<<1)|1)
#define ll long long
#define ull unsigned long long
 
using namespace std;

int n,q,ct;
int h[100100],nx[200200],to[200200],cnt;
int dfn[100100][2];
int lazy[400100],mx[400100];
bool st[100100];

inline void add(int f,int t) {
    nx[++cnt] = h[f]; h[f] = cnt; to[cnt] = t;
    nx[++cnt] = h[t]; h[t] = cnt; to[cnt] = f;
}

inline void dfs(int x,int fa) {
    dfn[x][0] = ++ct;
    for(int i = h[x]; i; i = nx[i])
        if(to[i] != fa) {
            dfs(to[i],x);
        }
    dfn[x][1] = ct;
}

void push(int id) {
    // cout << mx[id] << '+' << lazy[id] << endl;
    mx[lson] = (lazy[lson] = max(mx[lson],lazy[id]));
    mx[rson] = (lazy[rson] = max(mx[rson],lazy[id]));
    lazy[id] = 0;
}

inline void update(int l,int r,int L,int R,int id,int k) {
    if(L <= l && R >= r) {
        mx[id] = max(mx[id],k);
        lazy[id] = max(lazy[id],k);
        // cout << lazy[id] << "---" << id << "---" << mx[id] << endl;
        return;
    }
    if(lazy[id]) push(id);
    int mid = (l+r) >> 1;
    if(L <= mid) update(l,mid,L,R,lson,k);
    if(R >= mid+1) update(mid+1,r,L,R,rson,k);
}

inline int query(int l,int r,int x,int id) {
    if(l == r) {
        // cout << "-----x :" << x << "  ----id :" << id << endl;
        return mx[id];
    }
    if(lazy[id]) push(id);
    int mid = (l+r) >> 1;
    if(x <= mid) return query(l,mid,x,lson);
    else return query(mid+1,r,x,rson);
}

int main() {
    scanf("%d%d",&n,&q);
    int u,v;
    for(int i = 1; i < n; i++) {
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs(1,1);
    lazy[1] = 1;
    char x;
    int id;
    for(int i = 1; i <= q; i++) {
        cin >> x;
        if(x == 'C') {
            scanf("%d",&id);
            // cout << ct << " ----dfn1:" << dfn[id][0] << " ----dfn2:" << dfn[id][1] << " ----id:" << id << endl;
            if(!st[id]) update(1,ct,dfn[id][0],dfn[id][1],1,id),st[id] = 1;
        } else {
            scanf("%d",&id);
            // cout << "-----dfn :" << dfn[id][0] << endl;
            printf("%d\n",query(1,ct,dfn[id][0],1));
        }
    }
}