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

char arr[200000],brr[200000];
int a[2],b[2];
struct stu {
	int first,second;
}e[500010];
int cnt;

int main() {
	io_f;
	cin>>arr>>brr;
	int l1=strlen(arr);
	int l2=strlen(brr);
	int x1=0,x2=0;
	for(int i=1;i<l1;i++) a[arr[i]-'a']++,if(arr[i]!=arr[i-1]) x1++;
	for(int i=1;i<l2;i++) b[brr[i]-'a']++,if(brr[i]!=brr[i-1]) x2++;
	// int x1=max(a[1],b[0]);
	// int x2=max(b[1],a[0]);
	bool st=0;
	if(>=x2)st=1;
	int ans=0;l1--;l2--;
	int ct=0;
	while(l1!=-1||l2!=-1) {
		while(arr[l1]=='a'+(st+ct)%2&&l1>=0)l1--;
		while(brr[l2]!='a'+(st+ct)%2&&l2>=0)l2--;
		if(l1!=-1||l2!=-1)  {
			ans++;
			e[++cnt].first=l1+1;e[cnt].second=l2+1;
		}
		
		while(arr[l1]!='a'+(st+ct)%2&&l1>=0)l1--;
		while(brr[l2]=='a'+(st+ct)%2&&l2>=0)l2--;
		ct++;
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++) {
		if(i%2)cout<<e[i].first<<' '<<e[i].second<<endl;
		else cout<<e[i].second<<' '<<e[i].first<<endl;
	}
	return 0;
}
