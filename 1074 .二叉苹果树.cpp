#include <bits/stdc++.h> //树型dp--依赖背包
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
const int N = 110, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx, w[N];
int st[N];
int f[N][N];
int res;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u)
{
    st[u] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        if (st[son])
            continue;
        dfs(son);
        for (int j = m; j >= 0; j--)// 枚举体积 (u的所有可能体积)
        // 枚举决策 (子节点son中分配k个体积,需要给u->som留一个，son子树中就少1个,k<j)
            for (int k = 0; k < j; k++)
                f[u][j] = max(f[u][j], f[u][j - 1 - k] + f[son][k] + w[i]);
    }
}
void solve()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(b, a, c), add(a, b, c);
    }
    dfs(1);
    cout << f[1][m];
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
