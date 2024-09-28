#include <bits/stdc++.h>//数位dp 

using namespace std;
typedef long long LL;

const int N = 20;
const LL mod = 1e9 + 7;

LL a[N];    // 用于拆分十进制每一位的数组
LL base[N]; // 预处理出的10的幂次方

struct Node {
    LL s0; // 满足条件数的个数 Σ(k,1)
    LL s1; // 满足条件的数的和 Σ(k,A)
    LL s2; // 满足条件的数的平方的和Σ(k,A^2)
} f[N][7][7];

/*
维度1：u: 数位位置
维度2：sum: 前面完成数位的数位和mod 7
维度3：pre: 前面的类前缀和 mod 7
*/

// 枚举位置,每一位加起来的和%7,这个数%7,是不是贴上界
Node dfs(int u, int sum, int pre, bool op) {
    // 1、当u==0时,当sum不是7的倍数,并且,pre不是7的倍数时,这个数是合法的,个数记为1返回
    // 2、为什么返回的sum==0,pre==0呢？因为这是要返回上一层去算的,这句话还需要仔细体会含义
    if (u == 0) return {(sum && pre), 0, 0};

    // 记忆化
    if (!op && ~f[u][sum][pre].s0) return f[u][sum][pre];
    // 上界
    int up = op ? a[u] : 9;

    // 本状态下u+sum+pre 的统计信息
    Node ans = {0, 0, 0};
    for (int i = 0; i <= up; i++) {
        if (i == 7) continue;
        Node ret = dfs(u - 1, (sum + i) % 7, (pre * 10 + i) % 7, op && (i == up));
        // 汇集个数
        ans.s0 = (ans.s0 + ret.s0) % mod;
        // 汇集数字和
        ans.s1 = (ans.s1 + ret.s0 * i % mod * base[u - 1] % mod + ret.s1) % mod;
        // 汇集数字平方和
        ans.s2 = (ans.s2 + i * base[u - 1] % mod * i % mod * base[u - 1] % mod * ret.s0 % mod) % mod;
        ans.s2 = (ans.s2 + 2 * i % mod * base[u - 1] % mod * ret.s1 % mod + ret.s2) % mod;
    }
    // 套路
    if (!op) f[u][sum][pre] = ans;
    return ans;
}

LL calc(LL x) {
    int al = 0;
    while (x) a[++al] = x % 10, x /= 10;
    return dfs(al, 0, 0, true).s2;
}

int main() {
    // 与7无关的数，是数字本身的特性，而且取模是一个固定值，不会因为多输入几次就变化
    memset(f, -1, sizeof(f));

    // 预处理出10的幂次方【因为涉及到取模，要不这玩意还用预处理？】
    base[0] = 1;
    for (int i = 1; i < N; i++) base[i] = base[i - 1] * 10 % mod;

    int T;
    cin >> T;
    LL l, r;
    while (T--) {
        cin >> l >> r;
        printf("%lld\n", (calc(r) - calc(l - 1) + mod) % mod); // 操作的每一步都需要注意取模
    }
    return 0;
}

