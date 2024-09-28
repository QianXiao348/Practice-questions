#include <bits/stdc++.h> //单调队列优化dp
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 10000007;
const double eps = 1e-8;
const int N = 1010;
int n, m, k;
int w[N][N];
int f[N];
int q[N], hh, tt;
void get_min(int a[], int b[], int col)
{
    int hh = 0, tt = -1; // 和前缀和相关的，才会有哨兵。这里和前缀和没关系，不用加入哨兵。
    for (int i = 1; i <= col; i++)
    {
        //举栗子：比如i=5,k=3,则窗口范围是[3,4,5],也就是最远的队头元素下标是i-k+1,再比它小就不行了
        while (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;
        //此处需要包括i本身，所以在添加到队列后进行计算
        b[i] = a[q[hh]];
    }
}
void get_max(int a[], int b[], int col)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= col; i++)
    {
        while (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    /*步骤I：遍历每一行，完成最小值、最大值的向右转储，分别记录到row_min、row_max两个数组中。
    这两个数组，只是一个中间的状态，是为了给步骤II“竖着计算k个范围内的极大极小值”提供垫脚石的
    */
    int row_max[N][N];
    int row_min[N][N];
    for (int i = 1; i <= n; i++)
    {
        get_min(w[i], row_min[i], m);
        get_max(w[i], row_max[i], m);
    }
    int t[N], a[N], b[N];
    /*
    步骤II:将竖向的区间极值向右下角归并
      (1)、依托row_min，对每一列进行列转行，保存为t
      (2)、利用get_min 将t数组再次存储为a数组
      (3)、此a数组，就是左归右，上归下的，边长为k的矩形中的最小值　

      (4)、依托row_max，对每一列进行列转行，保存为t
      (5)、利用get_max 将t数组再次存储为b数组
      (6)、此b数组，就是左归右，上归下的，边长为k的矩形中的最大值　
    */
    int res = INT_MAX;
    for (int j = k; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
            t[i] = row_min[i][j];
        get_min(t, a, n);
        for (int i = 1; i <= n; i++)
            t[i] = row_max[i][j];
        get_max(t, b, n);
        for (int i = k; i <= n; i++)
            res = min(res, b[i] - a[i]);
    }
    cout << res << endl;
}
int main()
{
    // freopen("in.txt", "rt", stdin);
    // freopen("out.txt", "wt", stdout);
    PASE;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
