#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ci const int&
#define cl const long long&
#define cul const unsigned long long&
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

int n,m;
ull cnt = 19260817;

int main() {
    srand(time(NULL)*cnt);
    n = rand() % 50001;
    srand(time(NULL)*(cnt*=cnt));
    m = rand() % 50001;
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= m; i++) {
        srand(time(0)*(cnt++)*i);
        int l = rand() % (n+1);
        while(1) {
            srand(time(0) * (cnt++) * (ull)i);
            int r = rand() % (n+1);
            if (l + r <= n) {
                r += l;
                cout << l << ' ' << r << endl;
                break;
            }
        }
    }
    return 0;
}