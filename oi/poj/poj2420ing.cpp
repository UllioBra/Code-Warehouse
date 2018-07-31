#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
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
#define cdu const double&
#define cl const long long&
#define cul const undigned long long&
using namespace std;

template <class T>
bool scan_d(T &ret){
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0;
	while(c!='-'&&c!='.'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	if(c==' '||c=='\n'){ ret*=sgn; return 1; }
	return 1;
}

template <class E>
inline void out(const E&x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}		

const double k=1.3806505;
const double Eps=0.4;
const double pi=acos(-1);
double t;
int n;
int min_x=0x3f3f3f3f,min_y=0x3f3f3f3f,max_x,max_y;
int mv[4][2]={
	{0,1},{1,0},{0,-1},{-1,0}
};
struct point_ {
	int x,y;
}arr[101];

inline double dist(ci i,cdu x,cdu y) {
	return sqrt(pow(arr[i].x-x,2.0)+pow(arr[i].y-y,2));
}

inline double random(ci x,ci y) {
	srand(t*k*pi);
	return (double)(rand()%19260817)/19260818;
}

inline void get_rand(double&a,double&b,cdu x,cdu y,ci i) {
	a=x+mv[i][0]*(t/pi);
	b=y+mv[i][1]*(t/pi);
	if(a>max_x)a=max_x;
	if(a<min_x)a=min_x;
	if(b>max_y)b=max_y;
	if(b<min_y)b=min_y;
}

void SA() {
	double x=(min_x+max_x)/2.0,y=(min_y+max_y)/2.0;
	double x1,y1;
	double bst=1e9;
	while(t>Eps) {
		for(int i=0;i<4;i++) {
			get_rand(x1,y1,x,y,i);
			double as=0.0; 
			for(int i=1;i<=n;i++)
				as+=dist(i,x1,y1);
			if(as<bst||exp(-(as-bst)/(t/k))>random(0,1)) {
				bst=as;
				x=x1;y=y1;
				t/=2.1;
			}
		}
	}
	cout<<round(bst)<<endl;
}

int main() {
	scan_d(n);
	t=1000.0;
	for(int i=1;i<=n;i++) {
		scan_d(arr[i].x);
		scan_d(arr[i].y);
		min_x=min(min_x,arr[i].x);
		min_y=min(min_y,arr[i].y);
		max_x=max(max_x,arr[i].x);
		max_y=max(max_y,arr[i].y);
	}

	SA();

	return 0;
}