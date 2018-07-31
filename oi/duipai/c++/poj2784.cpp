#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
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
using namespace std;

const double pi=acos(-1);
const int mod=2971;
int cnt=1;
inline ull get_rand() {
	srand(time(0));
	return rand()*++cnt*(clock()+999)/1000;
}
ull n;
ull q;
bool mp[3001][3001];

int main() {
	n=get_rand()%1001;
	q=get_rand()%9;
	cout<<n<<' '<<q<<endl;
	for(int i=1;i<=q;i++) {
		ull tmp=get_rand()%n;
		cout<<tmp<<' '<<get_rand()%n<<' ';
		ull num=0;
		for(ull j=1;j<=n&&num<tmp;j++)
			if(n-j+1==tmp-num||j*get_rand()/pi>get_rand())
				cout<<j<<' ',num++;
		cout<<endl;
	}
	for(int i=1;i<=n;i++) {
		int x=get_rand()%mod;
		int y=get_rand()%mod;
		if(!mp[x][y])
		cout<<x<<' '<<y<<endl,mp[x][y]=1;
	}

	return 0;
}
