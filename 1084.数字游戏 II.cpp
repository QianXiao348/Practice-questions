#include <bits/stdc++.h> //数位dp 

using namespace std;

const int N = 32;
const int M = 100; // n<=100,所有 mod n 的结果最大是99

int mod;
int a[N], al;
int f[N][M];

int dfs(int u, int st, bool op) {
    if (u == 0) return st % mod == 0; // 各位数字和 %n == 0就是一个答案

    if (!op && ~f[u][st]) return f[u][st];

    int ans = 0, up = op ? a[u] : 9;
    for (int i = 0; i <= up; i++)
        ans += dfs(u - 1, (st + i) % mod, op && i == a[u]);

    if (!op) f[u][st] = ans;
    return ans;
}

int calc(int x) {
    // 疑问：为什么本题不能将memset放在整体上呢？是因为取模造成的吗？
    // 答：是的，因为n是每次全新输入的,如果有兴趣，可以再加一维，维护n
    memset(f, -1, sizeof f);
    al = 0;
    while (x) a[++al] = x % 10, x /= 10;
    // 某人又命名了一种取模数，这种数字必须满足各位数字之和 mod N 为 0。
    // 前0位数字和为0,st = 0
    return dfs(al, 0, true);
}

int main() {
    int l, r;
    while (cin >> l >> r >> mod)
        printf("%d\n", calc(r) - calc(l - 1));
    return 0;
}
