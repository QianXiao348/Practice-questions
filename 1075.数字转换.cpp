#include <bits/stdc++.h> //树型dp--最长直径 
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 1e8;
const double eps = 1e-8;
const int N = 5e4 + 10, M = N * 2;
int n;
int h[N], e[M], ne[M], idx;
int d1[N], d2[N], st[N]; // 最长路径  次长路径
int sum[N];//存每个数的约数和 
int res;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
// 求树的直径模板
void dfs(int u)
{
    st[u] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (st[j])
            continue;
        dfs(j);
        int d = d1[j] + 1;
        if (d >= d1[u])
            d2[u] = d1[u], d1[u] = d;
        else if (d > d2[u])
            d2[u] = d;
    }
    res = max(res, d1[u] + d2[u]);
}
void solve()
{
    cin >> n;
    memset(h, -1, sizeof h);
    // 筛法求约数和
    for (int i = 1; i <= n; i++)         // i是因数
        for (int j = 2; j <= n / i; j++) // j代表i的放大倍数 n/i不会溢出
            sum[i * j] += i;             // i*j的约数和+i

    for (int i = 1; i <= n; i++)
        if (sum[i] < i)
            add(sum[i], i);
    dfs(1);
    cout << res;
}
int main()
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    PASE;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
