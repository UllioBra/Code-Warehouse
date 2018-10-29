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

int n;

int main() {
    scanf("%d",&n);
    if(!(n%2)) {
        printf("No\n");
    } else {
        printf("Yes\n2\n");
        for(int i = 1; i <= (n+1)/2; i++)
            printf("%d ",i);
        printf("\n");
        for(int i = (n+1)/2; i <= n; i++)
            printf("%d ",i);
    }
}