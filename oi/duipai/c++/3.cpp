#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
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
#define cul const unsigned long long&
#define io_f std::ios::sync_with_stdio(false)
using namespace std;



int main() {
    srand(time(NULL));
    srand(rand());
    int n = rand()%1001;
    cout<<n<<endl;
    int cnt = 1;
    for (int i = 1;i <= n;i++)
    {
        srand(time(NULL)*(++cnt)*cnt|19260817);
        cout<<rand()%100<<endl;
    }
    return 0;
}