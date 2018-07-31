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

int n;
ll arr[400210];

inline ull min(ull x,ull y) {
	return x<y?x:y;
}

int main() {
	io_f;
	cin>>n;
	int a,b;
	for(int i=1 ; i<=n ; i++) {
		cin>>arr[i]>>arr[i+n];
	}
	sort(arr+1,arr+2*n+1);
	ull ans=(arr[n]-arr[1])*(arr[2*n]-arr[n+1]);
	for(int i=2;i<=n;i++) {
		ans=min(ans,(arr[n+i-1]-arr[i])*(arr[2*n]-arr[1]));
	}
	cout<<ans;
	return 0;
}
