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
#define cul const undigned long long&
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

int n,m;
int arr[101];

inline bool cmp(ci x,ci y) {
	return x>y;
}

inline bool check(ci x) {
	int tmp=n;
	for(int i=1;i<=m&&tmp>0;i++) {
		tmp-=arr[i]/x;
	}
	if(tmp<=0)return 1;
	return 0;
}

int main() {
	io_f;
	int a;
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		cin>>a;
		arr[a]++;
	}
	sort(arr+1,arr+100+1,cmp);
	int l=0,r=200;
	while(l+1<r) {
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;

	return 0;
}
