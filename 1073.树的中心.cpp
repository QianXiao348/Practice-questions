#include <bits/stdc++.h> //����dp--����dp
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
int h[N], e[M], ne[M], w[M], idx;
int d1[N], d2[N], up[N], id[N];//d1�����·����d2���´γ�·����up�����·����id�ǽڵ������ߵ��·���Ǵ���һ���ڵ���ȥ�� 
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
// ����:��uΪ������Ҷ�ӽ��еݹ飬�����ӽڵ㷵�ص����Ϣ�������Լ�����ʹγ�,����¼��Ǵ��ĸ��ڵ�����
void dfs_d(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        dfs_d(j, u);
        int d = d1[j] + w[i];
        if (d >= d1[u]) // ��������γ�����¼���Դ 
            d2[u] = d1[u], d1[u] = d, id[u] = j;
        else if (d > d2[u])
            d2[u] = d;
    }
}
// ���ܣ�������ϵ���Ϣ���
void dfs_u(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        if (id[u] == j)
            up[j] = max(d2[u], up[u]) + w[i];
        else
            up[j] = max(d1[u], up[u]) + w[i];
        dfs_u(j, u);
    }
}
void solve()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs_d(1, -1);
    dfs_u(1, -1);
    int res = INF;
    for (int i = 1; i <= n; i++)
        res = min(res, max(d1[i], up[i]));
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
