#include <bits/stdc++.h> //数位dp 
using namespace std;

const int N = 15;
int a[N], al;
int f[N][N];

// st代表前一数位上的数值
int dfs(int u, int st, bool lead, bool op) {
    if (u == 0) return 1;                           // 如果到头了，那么当前检查的数字是OK的
    if (!op && !lead && ~f[u][st]) return f[u][st]; // 不贴上界，非前导零，计算过

    int ans = 0, up = op ? a[u] : 9;
    for (int i = 0; i <= up; i++) {
        if (abs(st - i) < 2) continue; // 相邻两个数字，差不能小于2
        if (lead && i == 0)            // 继续前导零
            ans += dfs(u - 1, -2, true, op && i == a[u]);
        else // 不再是前导零
            ans += dfs(u - 1, i, false, op && i == a[u]);
    }
    // 不贴上界，非前导零，记录下来结果
    if (!op && !lead) f[u][st] = ans;
    return ans;
}

int calc(int x) {
    al = 0;
    while (x) a[++al] = x % 10, x /= 10;
    return dfs(al, -2, 1, 1); //     注意st的初始化-2
}

signed main() {
    int l, r;
    cin >> l >> r;
    // windy数是数字本身的一种性质，可以将memset放在外层
    memset(f, -1, sizeof f);

    cout << calc(r) - calc(l - 1) << endl;
    return 0;
}

