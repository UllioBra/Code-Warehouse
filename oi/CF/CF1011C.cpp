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

const double eps=1e-10;
int n,m;
int a[1001],b[1001];

inline bool check(double x) {
	x-=(x+m)/a[1];
	for(int i=2;i<=n;i++) {
		x-=(x+m)/b[i];
		x-=(x+m)/a[i];
	}
	x-=(x+m)/b[1];
	return x>=0;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	double l=-0.0,r=1e9+107;
	while(r-l>=eps) {
		double mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(r>1e9+100)printf("-1\n");
	else printf("%.8f\n",l);
	return 0;
}
