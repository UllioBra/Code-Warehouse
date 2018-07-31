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

int n;

int main() {
	io_f;
	int a;
	int bs=0;
	cin>>n;
	for(int i=1;i<=n ; i++) {
		cin>>a;
		bs+=a;
	}
	for(int i=1 ; i<=n ; i++) {
		cin>>a;
		bs-=a;
	}
	if(bs>=0)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
