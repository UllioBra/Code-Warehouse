# **题目描述**

```json
有 n 个整数，a1 一直到 an，按照下标从 1 到 n 排列到一行。接下来 m 个操作，每次选取下
标 x，并将下标大于等于 x 且不比 a[x]大的数字取出来，按照从小到大排序，之后放回所取
下标的位置。你要计算出初始的逆序对数以及每次操作后的逆序对数。  
比如有 5 个数字，2 3 4 5 1，我们选下标 1，那么把下标 1 之后且不小于 2 的取出来，变成
成了 _ 3 4 5 _,把 2 1 排序变成 1 2，放回去变成 1 3 4 5 2。  
```

# **输入输出格式**

## 输入格式

```json
第一行包含三个整数 n，m，表示数个数和操作的次数。
接下来 n 个数字，a1,a2……an，ai 可能相同，分别表示编号 1，2……n。最
后 m 行，每行一个数字，表示要选取的下标。

```

## 输出格式

```json
输出 m+1 的整数，分别是一开始的逆序对数，进行了 i 次操作后的逆序对数。
```

## 数据范围

```json
0<=ai<=1e6
对于 40%的数据，1 <= n <= 20，1 <= m <= 20。
对于 70%的数据，1 <= n，m <= 10^3。
对于 100%的数据，1 <= n，m <= 10^5
```

# **样例**

样例一输入:

```json
3 2
2 3 1
1
1
```

样例一输出:

```json
2
1
1  
初始的逆序对数为 2，当选中第一个数的时候，后面小于 2 的数只有 1，排序后变成 1，2，
然后放回那些取的位置，变为 1 3 2，逆序对数变成了 1。再次选中第一个数，后面没有小
于 1 的数，所以都不会动，逆序对数不变。
```

# **思路**

## 1.40%数据

暴力换,暴力算  
期望时间复杂度 $ \Theta \left( m n^{2} \right) $

## 2.70%数据

暴力换,归并算  
期望时间复杂度 $ \Theta \left( mn \log n \right) $

```cpp
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

int n,m,ans;
int q[1010],id[1010],r;
int a[1010];
int b[1010];
int tmp[1010];

void merge(int l,int r) {
    if(l == r) return;
    int mid = (l+r) >> 1;
    merge(l,mid);
    merge(mid+1,r);
    int le = l, ri = mid+1;
    for(int i = l; i <= r; i++) {
        if(le > mid || (a[le] > a[ri] && ri <= r)) {
            tmp[i] = a[ri++];
        } else if(ri > r || (a[le] <= a[ri] && le <= mid)) {
            tmp[i] = a[le++];
            ans += ri - (mid+1);
        }
    }
    for(int i = l; i <= r; i++)
        a[i] = tmp[i];
}

inline void cpy(int*f,int*t,int le) {
    for(int i = 1; i <= le; i++)
        f[i] = t[i];
}

int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    int x;
    cpy(b,a,n);
    merge(1,n);
    printf("%d\n",ans);
    for(int i = 1; i <= m; i++) {
        cpy(a,b,n);
        ans = 0;
        scanf("%d",&x);
        r = 0;
        for(int j = x; j <= n; j++)
            if(a[x] >= a[j]) {
                q[++r] = a[j];
                id[r] = j;
            }
        // cout << r << "+" << q[r] << endl;
        sort(q+1,q+1+r);
        for(int j = 1; j <= r; j++)
            a[id[j]] = q[j];
        cpy(b,a,n);
        merge(1,n);
        printf("%d\n",ans);
    }   
}
```

## 3.100%数据

显然,选出的数字对逆序对的贡献会变为0  
那么维护每个数字对答案的贡献,是否选择过  
再预处理一下区间最小值  
二分答案找下一个小于等于选择数字的位置即可  
期望时间复杂度 $ \Theta \left( n \log n \right) $

```cpp
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

const int mx_a = 1e6+10;
const int mx_n = 1e5+10;
const int inf = 1e9+111;
int n,m,d;
ll ans;
int a[mx_n];
ll w[mx_n];
bool vis[mx_n];
int mn[mx_n<<2];
int sum[mx_a<<2];

inline void update(int l,int r,int x,int id) {
    if(l == r) {
        mn[id] = inf;
        return;
    }
    int mid = (l+r) >> 1;
    if(x <= mid) update(l,mid,x,lson);
    else update(mid+1,r,x,rson);
    mn[id] = min(mn[lson],mn[rson]);
}

inline int xiao(int l,int r,int L,int R,int id) {
    if(l >= L && r <= R) {
        return mn[id];
    }
    int mid = (l+r) >> 1;
    int mn = inf;
    if(L <= mid) mn = min(mn,xiao(l,mid,L,R,lson));
    if(R >= mid+1) mn = min(mn,xiao(mid+1,r,L,R,rson));
    return mn;
}

inline void insert(int l,int r,int x,int id) {
    if(l == r) {
        sum[id]++;
        return;
    }
    int mid = (l+r) >> 1;
    if(x <= mid) insert(l,mid,x,lson);
    else insert(mid+1,r,x,rson);
    sum[id] = sum[lson] + sum[rson];
}

inline int query(int l,int r,int x,int id) {
    if(x >= r) {
        return sum[id];
    }
    int mid = (l+r) >> 1;
    int su = 0;
    su += query(l,mid,x,lson);
    if(x >= mid+1) su += query(mid+1,r,x,rson);
    return su;
}

inline void build(int l,int r,int id) {
    if(l == r) {
        mn[id] = a[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    mn[id] = min(mn[lson],mn[rson]);
}

inline bool check(int r,int l) {
    // cout << a[d] << "-----" << xiao(1,n,l,r,1) << "---" << l << "---" << r << endl;
    return a[d] >= xiao(1,n,l,r,1);
}

inline int find(int x) {
    if(x == n) return n+1;
    int l = x+1,r = n,mid,ans = x;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(check(mid,x+1)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    // cout << ans << "-" << endl;
    update(1,n,x,1);
    return ans == x ? n+1 : ans;
}

int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);

    for(int i = n; i >= 1; i--) {
        insert(0,mx_a,a[i],1);
        if(a[i])w[i] = query(0,mx_a,a[i]-1,1),ans+=w[i];
    }
    printf("%lld\n",ans);

    // cout << endl;
    // for(int i = 1; i <= n; i++)
        // printf("%d ",w[i]);
    // cout << endl << endl;

    build(1,n,1);

    int x;
    for(int i = 1; i <= m; i++) {
        scanf("%d",&x);
        d = x;
        if(!vis[x]) {
            while(x <= n) {
                if(vis[x]) break;
                ans -= w[x];
                vis[x] = 1;
                // cout << x << "+" << endl;
                x = find(x);
                // cout << x << '+' << endl;;
            }
        }
        printf("%lld\n",ans);
        // cout << endl << endl;
    }   
}
```