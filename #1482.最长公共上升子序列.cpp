#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int> PII;
const int dx[] = {-1,0,1,0,-1,1,1,-1};
const int dy[] = {0,1,0,-1,1,1,-1,-1}; 
const int mod = 1e9+7; 
const int N = 3010;
int n, m;
int a[N], b[N];
int f[N][N]; // 动态规划数组
PII pre[N][N]; // 前驱数组，用于记录路径
int c[N]; // 用于存储最终结果的数组

int main() {
    PASE; // 优化输入输出
    cin >> n; // 输入第一个序列的长度
    for (int i = 1; i <= n; i++) cin >> a[i]; // 输入第一个序列
    cin >> m; // 输入第二个序列的长度
    for (int i = 1; i <= m; i++) cin >> b[i]; // 输入第二个序列

    int ans = 0, ans_i = 0, ans_j = 0; // 用于记录最长子序列的长度及其结束位置
    for (int i = 1; i <= n; i++) {
        int mx = 0, mj = 0; // 临时变量，用于记录当前最优解及其位置
        for (int j = 1; j <= m; j++) {
            if (a[i] != b[j]) {
                // 如果a[i]和b[j]不相等，直接继承前面的状态
                f[i][j] = f[i - 1][j];
                pre[i][j] = pre[i - 1][j];
            } else {
                // 如果a[i]和b[j]相等，更新当前状态
                f[i][j] = mx + 1;
                pre[i][j] = {i - 1, mj};
            }
            // 更新临时变量mx和mj
            if (b[j] < a[i] && mx < f[i - 1][j]) {
                mx = f[i - 1][j];
                mj = j;
            }
            // 更新全局最优解
            if (ans < f[i][j]) {
                ans = f[i][j];
                ans_i = i;
                ans_j = j;
            }
        }
    }

    cout << ans << endl; // 输出最长子序列的长度
    int q = ans, i = ans_i, j = ans_j;
    while (q) {
        if (j) c[q--] = b[j]; // 逆序存储子序列
        auto &it = pre[i][j];
        i = it.fi, j = it.se;
    }
    for (int k = 1; k <= ans; k++) cout << c[k] << " "; // 输出最长子序列
    return 0;
}

