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
bool book[1<<19];

inline void print () {
    for (int i = 1; i <= (1 << n) - 1; i++)
        cout << book[i];
}

int main() {
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
        book[arr[i]] = 1;
    }

    if (m == 0) {
        int i = (1 << n) - 1 ;
        int sum = 0;
        while(sum < k) {
            if (!book[i]) {
                sum++;
                book[i] = 1;
            }
            i--;
        }
        print();
        return 0;
    }

    if (m <= 1) {
        if (k == 0) {
            cout << -1 << endl;
            return 0;
        }
        int i = (1 << n) - 1 ;
        int sum = m;
        while(sum < k) {
            if (!book[i]) {
                sum++;
                book[i] = 1;
            }
            i--;
        }
        print();
        return 0;
    }
    
    for (int i = 1; i <= (1 << n) - 1; i++)
        for (int j = i + 1; j <= (1 << n) - 1; j++)
            if (book[i] && book[j]) book[i|j] = 1;

    int sum = 0;
    for (int i = 1; i <= (1 << n) - 1; i++)
        if (book[i]) sum++;
    
    if (sum > k) {
        cout << -1 << endl;
        return 0;
    }
    int i = (1 << n) - 1 ;
    while(sum < k) {
        if (!book[i]) {
            sum++;
            book[i] = 1;
        }
        i--;
    }
    print();
    return 0;
}