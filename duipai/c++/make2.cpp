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

ull sum,num;
int cnt=1;

int main() {
	sum=rand()*cnt++*(clock()+999)/1000;
	sum%=100001;
	num=rand()*++cnt*(clock()+998)/1000;
	num%=11;
	cout<<sum<<' '<<num<<endl;
	for(int i=1;i<=num;i++) {
		ull x=rand()*cnt++*(clock()+999)/1000;
		ull y=rand()*cnt++*(clock()+999)/1000;
		cout<<x%1001<<' '<<y%1001<<endl;
	}
	return 0;
}
/*
*/
/*
poj1276
*/
