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

int n,q;
int val[10];
bool bel[10][1010];
int x[1010],y[1010];

struct stu {
	int f,t;
	ull x;
	bool operator < (const stu&a)const {return x<a.x;}
}arr[1000010],brr[1010];
int cnt,ct;

int bcj[1010];

int find_(ci x) {
	return x==bcj[x]?x:bcj[x]=find_(bcj[x]);
}

int main() {
	io_f;
	int a,b;
	cin>>n>>q;
	for(int i=1;i<=q;i++) {
		cin>>a>>val[i];
		for(int j=1;j<=a;j++){
			cin>>b;
			bel[i][b]=1;
		}
	}
	for(int i=1;i<=n;i++) {
		cin>>x[i]>>y[i];
		for(int j=i-1;j>=1;j--)
			arr[++cnt]=(stu){j,i,(ull)pow(x[i]-x[j],2.0)+(ull)pow(y[i]-y[j],2.0)};
	}
	sort(arr+1,arr+cnt+1);
	ull ans=0;
	for(int i=1;i<=n;i++) bcj[i]=i;
	for(int i=1;i<=cnt&&ct<=n-1;i++) {
		stu c=arr[i];
		if(find_(c.f)==find_(c.t))continue;
		bcj[find_(c.f)]=find_(c.t);
		ans+=c.x;
		brr[++ct]=c;
	}
	for(int i=1;i<=(1<<q)-1;i++) {
		ull bs=0;
		for(int j=1;j<=n;j++)bcj[j]=j;
		for(int j=0;(1<<j)<=i;j++)
			if(i&(1<<j)) {
				bs+=val[j+1];
				int tmp=0;
				for(int k=1;k<=n;k++) if(bel[j+1][k]) {
					if(tmp==0)tmp=k;
					else bcj[find_(bcj[k])]=find_(tmp);
				}

			}
		for(int j=1;j<=ct;j++) {
			stu c=brr[j];
			if(find_(c.f)==find_(c.t))continue;
			bcj[find_(c.f)]=find_(c.t);
			bs+=c.x;
		}
		ans=min(ans,bs);
	}
	cout<<ans<<endl;
	return 0;
}
