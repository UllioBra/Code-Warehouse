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

bool mp[30];
int n,m;

int main() {
	char a;
	io_f;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a;
		mp[a-'a'+1]=1;
	}
	int ans=0;
	for(int i=1;i<=26&&m;i++) {
		if(mp[i]) {
			m--;
			ans+=i;
			i++;
		}
	}
	if(!m)cout<<ans;
	else cout<<-1;

	return 0;
}
