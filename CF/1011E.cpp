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

int n,k;

int gcd(ci x,ci y) {return y==0?x:gcd(y,x%y);}

int main() {
	io_f;
	int a,x;
	cin>>n>>k;
	x=k;
	for(int i=1;i<=n;i++) {
		cin>>a;
		x=gcd(x,a);
	}
	cout<<k/x<<endl;
	for(int i=0;i<k;i+=x) cout<<i<<endl;

	return 0;
}
