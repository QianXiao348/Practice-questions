#include <bits/stdc++.h>
using namespace std;
const int N = 20;     // 好小的上限N,大的没法状态压缩实现,2^N不能太大啊！
const int M = 1 << N; // 2的N次方
int w[N][N];          // 邻接矩阵，记录每两个点之间的距离
int f[M][N];          // DP状态数组,记录每一步的最优解
int n;                // n个结点
int main() {
    cin >> n;
    // 邻接矩阵
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    // 求最短，设最大
    memset(f, 0x3f, sizeof f);
    // ① 初始化,从0出发到0结束，路线状态表示为1
    f[1][0] = 0; // 从0走到0,路线为1，也就是二进制表示法为(1)_2,表示0出现过
    for (int i = 0; i < (1 << n); i++)      // 枚举所有路线
        for (int j = 0; j < n; j++)         // 枚举每个节点作为阶段性终点
            if (i >> j & 1) {               // 这个节点是不是包含在路径中
                for (int k = 0; k < n; k++) // 引入结点k,使得距离更短
                    // 需要满足i这个路径中除去j这个点，一定要包含k这个点
                    if ((i - (1 << j)) >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
            }
    // 最终经历了所有结点，并且最后停在n-1(最后一个点，因为坐标从0开始)这个点
    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}

