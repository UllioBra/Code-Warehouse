#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

const int mod=10001;
int main()
{
	int cnt=1;
	srand(time(NULL)*cnt++);
	int n=rand()%101;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) {
		srand(clock()*time(NULL)/1000*cnt++);
		printf("%d ",rand()%mod);
		srand(clock()*time(NULL)/1000*cnt++);
		printf("%d\n",rand()%mod);
	}
	return 0;
}
/*
Two-dimensional space
n coordinates
*/