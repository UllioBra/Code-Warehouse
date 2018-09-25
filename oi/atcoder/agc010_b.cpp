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

int n;
int arr[100010], d[100100];

int main() {
    cin >> n;
    int sum = 0;
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            d[i] = arr[1] - arr[n];
        } else d[i] = arr[i+1] - arr[i];
    }
    if (2*sum % (n*(n+1))) {
        cout << "NO";
        return 0;
    }
    num = 2*sum / (n*(n+1));
    for (int i = 1; i <= n; i++) {
        if (num - d[i] < 0 || (num - d[i]) % n) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}