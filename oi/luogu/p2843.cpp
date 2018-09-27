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

const ull mod = 1777777;
int n, k;
int arr[100010][31];
int brr[100010][31];

int h[2000000], nx[2000000], to[2000000], cnt;
inline void add (ull f, int t) {
    nx[++cnt] = h[f]; h[f] = cnt; to[cnt] = t;
}

inline ull Get_Hash(const int & id) {
    ull ans = 19260817;
    for (int i = 0; i < k; i++) {
        ans = ans * mod + brr[id][i];
        ans += mod;
    }
    return ans % mod;
}

inline void Hash_Insert(const int & id) {
    add(Get_Hash(id), id);
}

inline bool check(const int & x1, const int & x2) {
    for (int i = 0; i < k; i++)
        if (brr[x1][i] != brr[x2][i])
            return false;
    return true;
}

int main() {
    int a;
    cin >> n >> k;
    int ans = 0;
    Hash_Insert(0);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        for (int j = 0; j < k; j++) {
            if (a & (1 << j)) {
                arr[i][j] += 1;
            }
            arr[i][j] += arr[i-1][j];
            brr[i][j] = arr[i][j] - arr[i][0];
            // cout << i << '^' << brr[i][j] << '&' << j << endl;
        }
            
        for (int j = h[Get_Hash(i)]; j; j = nx[j]) {
            if (check(to[j], i)) {
                // cout << i << ' ' << to[j] << endl;
                ans = max(ans, i - to[j]);
            }
        }
        Hash_Insert(i);
    }
    // cout << '+' << endl;
    // int ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     // cout << i << endl;
    //     for (int j = h[Get_Hash(i)]; j; j = nx[j]) {
    //         if (check(to[j], i)) {
    //             cout << i << ' ' << to[j] << endl;
    //             ans = max(ans, i - to[j] + 1);
    //         }
    //     }
    // }
    cout << ans << endl;

    return 0;
}