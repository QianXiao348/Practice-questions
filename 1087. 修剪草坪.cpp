#include <bits/stdc++.h> //单调队列优化dp 
using namespace std;
const int N = 100010;
typedef long long LL;
int q[N];
LL s[N], f[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];

    // 由于滑动窗口在i的左边，需要讨论前缀和的s[l-1],第1个没有前序，不符合整体的代码逻辑，添加了一个哨兵
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) {
        // 　1、年龄大于m的老家伙们，不管是不是实力够强大，一概去死
        while (hh <= tt && i - q[hh] > m) hh++;

        // 因为滑动窗口在i 左侧，先使用再加入
        f[i] = max(f[i - 1], f[max(0, q[hh] - 1)] + s[i] - s[q[hh]]);

        // 　2、不如我年轻，并且，不如我有实力的老家伙们去死
        while (hh <= tt && f[i - 1] - s[i] >= f[max(0, q[tt] - 1)] - s[q[tt]]) tt--;

        // 3、i入队列
        q[++tt] = i;
    }
    // 输出结果
    cout << f[n] << endl;
    return 0;
}

