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
#define ci const int &
#define cl const long long &
#define cul const unsigned long long &
#define io_f std::ios::sync_with_stdio(false)
using namespace std;

int n, m, k;
int arr[10010];

inline void print(int x)
{
    for (int i = 0; i < (1 << n); i++)
        if (x & (1 << i))
            cout << 1;
        else
            cout << 0;
}

int main()
{
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> arr[i];
        ans |= 1 << (arr[i] - 1);
    }

    for (int i = 18; i >= 0; i--)
        for (int j = i - 1; j >= 0; j--)
            ans |= (i & j);

    int sum = 0;
    for (int i = 0; i <= 18; i++)
        if (ans & (1 << i))
            sum++;

    if (sum > k)
    {
        cout << -1 << endl;
        return 0;
    }
    int l = 0;
    while (sum < k)
    {
        if (!(ans & (1 << l)))
        {
            sum++;
            ans |= (1 << l);
        }
    }
    print(ans);

    return 0;
}