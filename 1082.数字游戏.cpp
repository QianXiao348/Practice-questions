#include <bits/stdc++.h>//数位dp 
using namespace std;
const int N = 32;
int l, r;
int a[N], al;
int f[N][N];
/**
 *
 * @param u 当前的数位
 * @param st  前一位填写的是什么
 * @param op  是不是贴上界
 * @return    在当前情况下，后续符合条件的有多少个
 */
int dfs(int u, int st, bool op) {
    if (u == 0) return 1; // 如果走完所有情况，还活着，说明前面的都符合条件，就是一个合理解++
    if (!op && ~f[u][st]) return f[u][st];
    int ans = 0, up = op ? a[u] : 9;
    for (int i = st; i <= up; i++) // 注意起始点,i >= st
        ans += dfs(u - 1, i, op && i == a[u]);

    if (!op) f[u][st] = ans;
    return ans;
}

int calc(int x) {
    al = 0;
    while (x) a[++al] = x % 10, x /= 10;
    return dfs(al, 0, true);
}

int main() {
    memset(f, -1, sizeof f);
    while (~scanf("%d%d", &l, &r))
        printf("%d\n", calc(r) - calc(l - 1));
    return 0;
}
