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

char n[2020];
int le,x;
int dp[1010][2];

int main() {
    scanf("%s %d",n,&x);
    le = strlen(n);
    printf("%d",dfs(0))
}