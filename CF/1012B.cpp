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

int n,m,q;
int bcj[400100];

int fd(ci x) {return x==bcj[x]?x:bcj[x]=fd(bcj[x]);}

int main() {
	io_f;
	int a,b;
	cin>>n>>m>>q;
	for(int i=1;i<=n+m;i++) bcj[i]=i;
	for(int i=1;i<=q;i++) {
		cin>>a>>b;
		bcj[fd(bcj[a])]=fd(bcj[b+n]);
	}
	int ans=0;
	for(int i=1;i<=n+m;i++)
		if(bcj[i]==i)ans++;
	cout<<ans-1<<endl;

	return 0;
}
