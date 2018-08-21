#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
string a;
int mp[1001],cnt;
bool arr[501][100];

int main() {
    int b;
    cin>>a>>n;
    for (int i = 0;i <= 9;i++) mp['0' + i] = ++cnt;
    for (int i = 'a';i <= 'z';i++) mp[i] = ++cnt;
    for (int i = 'A';i <= 'Z';i++) mp[i] = ++cnt;
    for (int i = 1;i <= n;i++) {
        cin >> b;
        for (int j = 1;j <= b;j++) {
            char c;
            cin>>c;
            arr[i][mp[c]] = 1;
        }
    }
    
}
