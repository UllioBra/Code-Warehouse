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
int arr[100005],brr[100005],crr[100005];
int sum[100005];
int num = 0;

void merge_sort(int l, int r, int&ans) {
    int mid = (l + r) >> 1;
    if (l < mid) merge_sort(l, mid, ans);
    if (r > mid + 1) merge_sort(mid + 1, r, ans);
    int h1 = l, h2 = mid + 1;
    for (int i = l; i <= r; i++) {
        if ((h1 > mid) || (h2 <= r && sum[h1] > sum[h2])) {
            crr[i] = sum[h2];
            ans += h1 - l;
            h2++;
        } else {
            crr[i] = sum[h1];
            h1++;
        }
    }
    for (int i = l; i <= r; i++)
        sum[i] = crr[i];
    return;
}

inline bool check (int x) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if(arr[i] <= brr[x]) sum[i] = sum[i-1] +1;
        else sum[i] = sum[i-1] - 1;
    }      
    merge_sort(0,n,ans);
    return ans >= (num/2 + 1);
}

int main () {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&arr[i]);
        brr[i] = arr[i];
        num += i;
    }

    sort(brr+1, brr+n+1);

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r ) >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;

    return 0;
}