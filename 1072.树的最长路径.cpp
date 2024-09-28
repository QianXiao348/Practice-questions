#include <bits/stdc++.h>//树型dp--最长路径 
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
const int N = 1e4 + 10, M = N * 2;
int n;
int w[M], h[N], e[M], ne[M], idx;
int ans;
int d1[N],d2[N];//最长 次长长度 
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
//求树的最长长度跟次长长度 
void dfs(int u, int fa) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == fa) continue; // v点访问过了
        // 走v子树,完成后，v子树中每个节点的mx1[v],d2[v]都已经准备好，u节点可以直接利用
        dfs(v, u);

        // w[i]:u->v的路径长度,mx1[u]:最长路径,d2[u]:次长路径
        int x = d1[v] + w[i];
        if (d1[u] <= x)                 // v可以用来更新u的最大值
            d2[u] = d1[u], d1[u] = x; // 最长路转移
        else if (d2[u] < x)
            d2[u] = x; // 次长路转移
    }
    // 更新结果
    ans = max(ans, d1[u] + d2[u]);
}
void solve()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1);
    cout << ans << endl;
}
int main()
{
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
    PASE;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
