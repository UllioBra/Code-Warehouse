<<<<<<< HEAD
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <math.h>
using namespace std;
int n;
int s[(1 << 20) + 100], dp[(1 << 20) + 100][2];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++)
    {
        scanf("%d", &s[i]);
        dp[i][1] = i;
    }
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = i | (1 << j);
            if (num != i)
            {
                if (s[dp[num][1]] < s[dp[i][1]])
                {
                    dp[num][0] = dp[num][1];
                    dp[num][1] = dp[i][1];
                }
                else if (s[dp[i][1]] > s[dp[num][0]] && dp[i][1] != dp[num][1])
                {
                    dp[num][0] = dp[i][1];
                }
                else if (s[dp[i][0]] > s[dp[num][0]])
                {
                    dp[num][0] = dp[i][0];
                }
                //printf("%d %d %d %d %d %d %d %d\n",i,dp[i][0],dp[i][1],num,dp[num][0],dp[num][1],s[dp[i][1]],s[dp[num][1]]);
            }
        }
    }
    /*for(int i=1;i<(1<<n);i++)
    {
        printf("%d %d\n",dp[i][0],dp[i][1]);
    }*/
    int ans = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        ans = max(ans, s[dp[i][0]] + s[dp[i][1]]);
        printf("%d\n", ans);
    }
=======
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
 
int n;
 
int main () {
    cin >> n;
    cout << n;
    return 0;
>>>>>>> d29182f3a7e45bace2726452a00eda0482650e7d
}