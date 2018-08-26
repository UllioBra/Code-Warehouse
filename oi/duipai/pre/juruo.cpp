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

int k[500000];
int arr[500000];
int n;

inline void deal(int x, int y)
{
    for (int i = x; i <= pow(2, n) - 1; i++)
        if (k[i] < y)
            k[i] = y;
        else
            return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < pow(2, n); i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= pow(2, n); i++)
        for (int j = i - 1; j >= 0; j--)
        {
            deal(i | j, arr[i] + arr[j]);
        }
    for (int i = 1; i <= pow(2, n) - 1; i++)
    {
        cout << k[i] << endl;
    }
    return 0;
}