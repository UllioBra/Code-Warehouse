#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#define ll long long
#define ull unsigned long long
#define ci const int&
#define cl const long long&
#define cul const unsigned long long&
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

int n,k;
int arr[1000000];

int main() {
    freopen("bubble.in","r",stdin);
    freopen("bubble.out","w",stdout);
    cin>>n>>k;
    for (int i = 1;i <= n;i++) {
        cin>>arr[i];
    }
    for (int i = 1;i <= k;i++)
        for (int j = 2;j <= n;j++)
            if (arr[j-1]>arr[j]) swap(arr[j-1],arr[j]);
    for (int i = 1;i <= n;i++) {
        cout<<arr[i]<<' ';
    }
        return 0;
}