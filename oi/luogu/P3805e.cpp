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
#define ci const int&
#define cl const long long&
#define cul const unsigned long long&
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

int le_a,le_b;
char a[11000000];
char s[22000200];
int ri[22000200];

inline void Init() {
    s[0] = '#';
    le_a = strlen(a);
    int now = 1;
    for(int i = 0; i < le_a; i++) {
        s[now++] = a[i];
        s[now++] = '#';
    }
}

inline void manacher() {
    int mx_r = 0,mid = 0,ans = 0;
    le_b = ((le_a<<1)|1);
    for(int i = 0; i < le_b; i++) {
        if(i < mx_r) {
            ri[i] = min(ri[(mid<<1)-i],ri[mid]+mid-i);
        } else ri[i] = 1;
        while(s[i+ri[i]] == s[i-ri[i]]) ++ri[i];
        if(ri[i] + i > mx_r) {
            mx_r = ri[i] + i;
            mid = i;
        }
        ans = max(ans,ri[i]);
    }
    printf("%d",ans);
}

int main() {
    scanf("%s",a);
    Init();
    manacher();
    return 0;
}