#include <bits/stdc++.h> //树型dp+状态机 
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
const int N = 6010, M = N * 2;
int n;
int h[N], e[M], ne[M], idx, w[N];
int st[N];
int in[N], f[N][2]; // 入度   f以u为根节点且参加状态是j的最大值(1包括u参加，0是u不参加)
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u)
{
    st[u] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (st[j])
            continue;
        dfs(j);
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][1], f[j][0]);
    }
    f[u][1] += w[u];
}
void solve()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(b, a);
        in[a]++;
    }
    int root = 1;
    while (in[root]) // 找到根节点
        root++;
    dfs(root);
    cout << max(f[root][1], f[root][0]) << endl;
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
