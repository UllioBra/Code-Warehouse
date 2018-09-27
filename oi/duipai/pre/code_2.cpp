#include <iostream>
#include <cstdio> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define LL long long 
#define mod 9901
using namespace std;
map<vector<int>,int>f;
int ans;
int main(){
    int n,m;scanf("%d%d",&n,&m);
    vector<int>now(m);
    f[now]=0;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        for(int j=0;j<m;j++)
            if(x&(1<<j))now[j]++;
        if(x&1)for(int j=0;j<m;j++)now[j]--;
        if(f.count(now))ans=max(ans,i-f[now]);
        else f[now]=i;
    }
    printf("%d\n",ans);
}