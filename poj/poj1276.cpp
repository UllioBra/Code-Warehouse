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
#define rint register int
#define ci const int&
#define cl const long long&
#define cul const undigned long long&
using namespace std;

template <class T>
bool scan_d(T &ret){
	char c; int sgn=1;
	while(c<'0'||c>'9') {if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
	ret=c*sgn;
	return 1;
}

template <class E>
inline void out(const E&x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}		

int cash;
int n;
int N[20],D[20];
bool dp[100100];

int main() {
	std::ios::sync_with_stdio(false);
	while(cin>>cash) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>N[i]>>D[i];
			if(!D[i]||!N[i])continue;
			N[i]=min(N[i],(cash+D[i]-1)/D[i]);
		}
		memset(dp,0,sizeof dp);
		dp[0]=1;
		int maxi=0;
		for(int i=1;i<=n;i++)
			for(int k=1;k<=N[i]&&k;N[i]-=k,k<<=1,k=min(k,N[i]))
				for(int j=min(cash-k*D[i],maxi);j>=0;j--) if(dp[j]) {
					maxi=max(maxi,j+k*D[i]);
					dp[j+k*D[i]]=1;
				}
		cout<<maxi<<endl;
	}

	return 0;
}
