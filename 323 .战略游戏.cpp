#include <bits/stdc++.h> //树型dp+状态机
using namespace std;
const int N = 1510;
int n, f[N][2]; // 以结点u为根节点 的子树，在 u上放置哨兵(1) 和不放哨兵(0) 的方案
int in[N];
int e[N], ne[N], h[N], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int fa)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa)
            continue;
        dfs(v, u);
        f[u][0] += f[v][1];
        f[u][1] += min(f[v][1], f[v][0]);
    }
    f[u][1] += 1;
}
int main()
{
    while (cin >> n)
    {
        memset(f, 0, sizeof f);
        memset(in, 0, sizeof in);
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d:(%d)", &x, &y);
            while (y--)
            {
                int z;
                cin >> z;
                add(x, z);
                in[z]++;
            }
        }
        int root = 0;
        while (in[root])
            root++;
        dfs(root, -1);
        cout << min(f[root][1], f[root][0]) << endl;
    }
    return 0;
}
