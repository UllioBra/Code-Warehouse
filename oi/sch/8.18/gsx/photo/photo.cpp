#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int bs=2000000;
int n;
int mp[2][4000001];

inline void deal (int&x,int&y,int z) {
    int t = y;
    y = x + z;
    x = y - z;
}

int main () {
    int le1 = 100000000,ri1 = -100000000,le2 = 100000000,ri2 = -100000000;
    int m1 = 0,m2 = 0;
    int x,y,z,d;
    cin>>n;
    for (int i = 1;i <= n;i++) {
        cin >> x >> y >> z >> d;
        if (y - x > z << 1) continue;
        if (d == -1) {
            deal(x,y,z);
            le1 = min(le1,x);
            ri1 = max(ri1,y);
            // cout<< x + bs<< y + bs<<endl;
            mp[0][x+bs]++;
            mp[0][y+bs]--;
        } else {
            deal(x,y,z);
            le2 = min(le2,x);
            ri2 = max(ri2,y);
            mp[1][y+bs]++;
            mp[1][x+bs]--;
        }
    }
    int e1 = 0,e2 = 0;
    for (int i = le1;i <= ri1;i++) {
        int tmp = i + bs;
        e1 += mp[0][tmp];
        m1 = max(m1,e1);
    }
    for (int i = ri2;i >= le2;i--) {
        int tmp = i + bs;
        e2 += mp[1][tmp];
        m2 = max(m2,e2);
    }
    cout<<m1 + m2<<endl;
}