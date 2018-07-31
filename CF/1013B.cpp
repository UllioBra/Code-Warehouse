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

int n,x;
bool mp1[100100];
bool mp2[100100];

int main() {
	io_f;
	int a;
	cin>>n>>x;
	int ans=-1;
	for(int i=1 ; i<=n ; i++) {
		cin>>a;
		if(mp1[a]) {
			ans=0;
			break;
		}
		if(mp2[a]||mp1[a&x]) {
			ans=1;
		}
		if(mp2[a&x]&&ans==-1) {
			ans=2;
		}
		mp1[a]=1;
		mp2[a&x]=1;
	}
	cout<<ans<<endl;
	return 0;
}
