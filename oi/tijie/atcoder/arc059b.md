# [**题目链接**](https://arc059.contest.atcoder.jp/tasks/arc059_b "arc059_b")
# **题目描述**
给定字符串S,求出S的一个子集,使得其中某一的字母的数量大于该子集字母数量的一半   
若存在输出该子集的头和尾的坐标,若不存在则输出两个 $ -1 $

## 数据范围:
$ 2≦|S|≦10^5 $   
$ S $ consists of lowercase letters.

# **思路**
## 1.暴力
发现每一个满足题意的S都一定包含一个长度为2或3的满足题意的子串   
也就是说只需要暴力查找一遍即可
```
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

string a;

int main() {
    cin >> a;
    int le = a.size();
    for (int i = 0; i < le - 1; i++) {
        if (a[i] == a[i+1]) {
            cout << i+1 << ' ' << i+2 << endl;
            return 0;
        } else if (a[i] == a[i+2] && i != le - 2) {
            cout << i+1 << ' ' << i+3 << endl;
            return 0;
        }
    }
    cout << -1 << ' ' << -1 << endl;
    return 0;
}
```