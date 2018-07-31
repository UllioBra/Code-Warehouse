#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1e9
const int maxn = 1005;
const int maxm = 1000005;
struct edge
{
    int from,to,dis;
    edge(int from,int to,int dis){
        this -> from = from;
        this -> to = to;
        this -> dis = dis;
    }
    edge(){}
};
struct node
{
    int cost;
    std::vector<int> v;
};
edge edges[maxm];
node nodes[11];
int par[maxn],rank[maxn];
int n,q,e;
int x[maxn],y[maxn];
void init()
{
    for(int i = 0;i <= n;i++){
        par[i] = i;
        rank[i] = 0;
    }
}
 
void add_edge(int from,int to,int dis)
{
    edges[e].from = from;
    edges[e].to = to;
    edges[e++].dis = dis;
}
 
int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}
 
void unite(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return ;
    if(rank[x] < rank[y]) par[x] = y;
    else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}
 
bool same(int x,int y)
{
    return find(x) == find(y);
}
 
bool cmp(edge a,edge b)
{
    return a.dis < b.dis;
}
 
int Kruskal()
{
    int res = 0;
    int cnt = 0;
    for(int i = 0;i < e;i++){
        edge ed = edges[i];
        if(same(ed.from,ed.to)) continue;
        unite(ed.from,ed.to);
        res += ed.dis;
        if(++cnt == n - 1) break;
    }
    return res;
}
 
int main(void)
{
    int a,b,c,d;
    scanf("%d %d",&n,&q);
        init();
        for(int i = 0;i <= q;i++) nodes[i].v.clear();
        e = 0;
        for(int i = 0;i < q;i++){
            scanf("%d %d",&a,&nodes[i].cost);
            while(a--){
                scanf("%d",&d);
                nodes[i].v.push_back(d);
            }
        }
        for(int i = 0;i < n;i++){
            scanf("%d %d",&x[i],&y[i]);
        }
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                int dis = pow(x[i] - x[j],2) + pow(y[i] - y[j],2);
                add_edge(i + 1,j + 1,dis);
            }
        }
        std::sort(edges,edges + e,cmp);
        int sum,res;
        res = Kruskal();
        for(int i = 0;i < 1 << q;i++){
            sum = 0;
            init();
            for(int j = 0;j < q;j++){
                if(!(i & (1 << j))) continue;
                sum += nodes[j].cost;
                int len = (int)nodes[j].v.size();
                for(int k = 1;k < len;k++){
                    unite(nodes[j].v[0],nodes[j].v[k]);
                }   
            }
            sum += Kruskal();
            res = std::min(res,sum);
        }
        printf("%d\n",res);
    return 0;
}
