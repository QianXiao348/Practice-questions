#include <bits/stdc++.h> //数位dp 
using namespace std;
const int N = 32; // 2^{32}足够int用了
int a[N], al;     // 数位分离拆开用的数组
int f[N][N];      // 第一维：第几位数；第二维：走到当前数位，已经取得了多少个
int n;            // 当前枚举到的是哪个数

/**
 u      :从高到低，现在是第几位数
 lead   :是否考虑前导零
 st     :到当前深度已经出现n的个数
 op     :是否贴上界
 返回值 :从当前数位u出发，在当前lead,st,op的前提下，可以得到多少个符合题意的数字
*/
int dfs(int u, int lead, int st, int op) {
    if (!u) return st;                              // 递归出口,u==0时，所有数位计算完毕，al是从1开始计数的
    if (!lead && !op && ~f[u][st]) return f[u][st]; // 非前导0 + 不贴上界 + 算过

    // u位上的最大值
    int up = op ? a[u] : 9; // 如果贴上界，则到op,否则可以全部取到

    int res = 0; // 按上面三个条件lead,st,op走到u这个数位时，最终可以获取到多少个数呢？
    for (int i = 0; i <= up; i++) {
        int sum = st;
        // ① 前面出现过非0数字 或者 本位置非0
        // ② 当前数位是要查找的数字
        if ((!lead || i > 0) && i == n) sum++;
        // 如果原来是贴上界，现在继续贴上界，那么贴上界继续
        res += dfs(u - 1, lead && !i, sum, op && i == a[u]);
    }

    // 记忆化
    if (!lead && !op) f[u][st] = res;
    return res;
}

int calc(int x) {
    al = 0;
    while (x) a[++al] = x % 10, x /= 10; // 高位在右,低位在左
    // al    :从al位开始
    // lead  :存在前导0
    // st    :前面填的数中数字n的个数是0个
    // op    :贴上界
    return dfs(al, 1, 0, 1);
}

int main() {
    int l, r;
    while (cin >> l >> r, l || r) {  
        if (l > r) swap(l, r);        // 谁大谁小还不一
        for (n = 0; n <= 9; n++) {    // 0,1,2,3,...个数都有多少个
            memset(f, -1, sizeof(f)); // 每轮需要初始化dp数组
            cout << calc(r) - calc(l - 1) << ' ';
        }
        cout << endl;
    }
    return 0;
}

