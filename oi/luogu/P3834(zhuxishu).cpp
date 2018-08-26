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
 
int n,m;
int arr[200020];
int brr[200020];
map <int,int> e;

const int le = 200000;
int root[200020];
int sum[le<<5],lson[le<<5],rson[le<<5],cnt;
 
void build(int l,int r,int&id) {
    if (!id) id = ++cnt;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(l,mid,lson[id]);
    build(mid+1,r,rson[id]);
}

void update(int l,int r,int L,int R,int&id,int&lid) {
    if (!id) id = ++cnt;
    if (L <= l && R >= r) {
        sum[id] = sum[lid] + 1;
        return;
    }
    int mid = (l+r) >> 1;
    if (L <= mid) {
        rson[id] = rson[lid];
        update(l,mid,L,R,lson[id],lson[lid]);
    } else {
        lson[id] = lson[lid];
        update(mid+1,r,L,R,rson[id],rson[lid]);
    }
    sum [id] = sum[lson[id]] + sum[rson[id]];
}

int query(int lid,int id,int k,int l,int r) {
    int mid = (l+r) >> 1;
    if (l == r) {
        return l;
    }
    int x = sum[lson[id]] - sum[lson[lid]];
    if (x >= k) 
        return query(lson[lid],lson[id],k,l,mid);
    else return query(rson[lid],rson[id],k-x,mid+1,r);
}

int main () {
    io_F;
    cin >> n >> m;

    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
        brr[i] = arr[i];
    }
    sort(arr + 1,arr + n + 1);

    int nn = unique(arr + 1,arr + n + 1) - arr;
    for (int i = 1;i <= nn;i++) {
        e.insert(pair<int,int>(arr[i],i));
    }
    // cout << nn <<endl;//
    build(1,nn,root[0]);
    // return 0;

    for (int i = 1;i <= n;i++) {
        update(1,nn,e[brr[i]],e[brr[i]],root[i],root[i-1]);
    }

    int l,r,k;
    for (int i = 1;i <= m;i++) {
        cin >> l >> r >> k;
        cout << arr[query(root[l-1],root[r],k,1,nn)] << endl;
    }

    return 0;
}