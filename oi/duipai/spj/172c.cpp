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

int n, m, k;
int arr[10010];
string a;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> arr[i];
    cin >> a; 
    if (a[0] == '-') {
        cout << 1;
        return 0;
    }
    int sum = 0;
    int le = a.size();
    for (int i = 1; i <= m; i++) 
        if (a[m-1] == '0') {
            cout << -1;
            return 0;
        }
    for (int i = 1; i <= le; i++)
        if (a[i-1] == '1') {
            sum++;
            if (sum > k) {
                cout << -1;
                return 0;
            }
            for (int j = i + 1; j <= le; j++)
                if (a[j-1] == '1') {
                    if (a[(i|j)-1] == '0') {
                        cout << -1;
                        return 0;
                    }
                }
        }
    cout << 1;
    return 0;
}