#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#define ci const int&
#define rint register int
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;

char arr[30],brr[30];
int lson[30],rson[30];
int le,x;

void dfs(ci l,ci r) {
	int fk=x;
	for(rint i=l;i<=r;i++) 
		if(brr[i]==arr[x]) {
			if(l<i) {
				lson[fk]=++x;
				dfs(l,i-1);
			}
			if(r>i) {
				rson[fk]=++x;
				dfs(i+1,r);
			}
			break;
		}
}


void print(ci id) {
	// for(rint i=0;i<le;i++)
	// 	cout<<arr[lson[i]]<<' '<<arr[rson[i]]<<endl;
	if(lson[id]) print(lson[id]);
	if(rson[id]) print(rson[id]);
	cout<<arr[id];
}

int main()  {
	while(~scanf("%s%s",arr,brr)) {
		x=0;
		memset(lson,0,sizeof lson);
		memset(rson,0,sizeof rson);
		le=strlen(arr);
		dfs(0,le-1);
		print(0);
		cout<<endl;
	}

    return 0;
}