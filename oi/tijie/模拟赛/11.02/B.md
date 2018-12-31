
# **题目描述**

9 个机器人，在 3 * 3 的方格里，一开始 9 个机器人分别站在 9 个格子上，每一步机器人可
以往临近的一个格子移动或留在原地（同一个格子可以有多个机器人停留），经过 n 步后有
多少种不同的走法，使得每个格子上都有 1 机器人停留。由于方法数量巨大，输出 Mod
10^9 + 7 的结果。

# **输入输出格式**

## 输入格式

第一行包含一个整数 n。

## 输出格式

输出一行输出走法的数量 Mod 10^9 + 7

## 数据范围

对于 40%的数据，1 <= n<= 10；  
对于 70%的数据，1 <= n <= 10^6；  
对于 100%的数据，1 <= n <= 10^18。  

# **样例**

样例一输入:

```json
1
```

样例一输出:

```json
299
```

# **思路**

## 1.40%数据
暴力  
期望复杂度 $ \Theta \left( 玄学 \right) $

## 2.70%数据

考虑dp  
dp[i][j][k] 表示走了i步,起点在j终点在k的方案数  
dfs枚举全排列  
期望复杂度 $ \Theta \left( 81n \right) $

## 3.100%数据

考虑优化dp转移  
很明显一个点朝其他点转移的状态量小且固定  
利用矩阵快速幂优化掉n  
期望复杂度 $ \Theta \left( 9^{3} \log n \right) $

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
const int mod = 1e9+7;
int dp[10][10];
bool mp[10];
ll n,ans;
ll e[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,1,0,0,0,0,0},
    {0,1,1,1,0,1,0,0,0,0},
    {0,0,1,1,0,0,1,0,0,0},
    {0,1,0,0,1,1,0,1,0,0},
    {0,0,1,0,1,1,1,0,1,0},
    {0,0,0,1,0,1,1,0,0,1},
    {0,0,0,0,1,0,0,1,1,0},
    {0,0,0,0,0,1,0,1,1,1},
    {0,0,0,0,0,0,1,0,1,1},
};

struct mat {
    ll p[10][10];
    mat(){memset(p,0,sizeof(p));}
    void cl() { for(int i=1;i<=9;i++) p[i][i]=1;}
    mat operator * (const mat&a)const {
        mat tmp;
        for(int k = 1; k <= 9; k++)
            for(int i = 1; i <= 9; i++)
                for(int j = 1; j <= 9; j++) {
                    tmp.p[i][j] += p[i][k] * a.p[k][j];
                    if(tmp.p[i][j] >= mod) tmp.p[i][j] %= mod;
                }
        return tmp;
    }
}XJH;

inline void Init() {
    memcpy(XJH.p,e,sizeof e);
}

mat ksm(mat bs,ll x) {
    mat ans;
    ans.cl();
    while(x) {
        if(x & 1) ans = ans * bs;
        bs = bs * bs;
        x >>= 1;
    }
    return ans;
}

void dfs(int step,ll sum) {
    if(step == 10) {
        ans += sum;
        if(ans >= mod) ans %= mod;
        return;
    }
    for(int i = 1; i <= 9; i++)
        if(!mp[i]) {
            mp[i] = 1;
            dfs(step+1,(sum * dp[i][step])%mod);
            mp[i] = 0;
        }
}

int main() {
    // freopen("B.in","r",stdin);
    // freopen("B.out","w",stdout);
    Init();
    scanf("%lld",&n);
    mat bs = ksm(XJH,n);
/*
    for(int i = 0; i <= 9; i++)
        for(int j = 0; j <= 9; j++)
            if(j == 9) cout << bs.p[i][j] << endl;
            else cout << bs.p[i][j] << ' ' ;
*/
    for(int i = 1; i <= 9; i++) {
        mat tmp;
        tmp.p[1][i] = 1;
        tmp = tmp*bs;
        for(int j = 1; j <= 9; j++)
            dp[i][j] = tmp.p[1][j];
    }
    dfs(1,1);
    printf("%lld",ans);
}
```