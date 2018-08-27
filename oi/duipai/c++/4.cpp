#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
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
#define cul const unsigned long long&
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

const int mod = 1e9+7;
int n;
ull cnt = 19260817;

int main() {
    srand(time(NULL)*(cnt|cnt));
    cnt *= cnt *cnt;
    n = rand() % 11;
    cout << n << endl;
    for (int i = 1; i <= (1<<n); i++) {
        srand(cnt* cnt* time(NULL));
        cout << (rand()*cnt++) % mod<<endl;
    }
    return 0;
}