#include <bits/stdc++.h>//bfs¼ÇÂ¼Â·¾¶£¬µ¹ÐòËÑË÷ 
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const int N = 1010;
int n;
int g[N][N];
bool st[N][N];
PII pre[N][N];
void bfs(int x, int y)
{
    queue<PII> q;
    q.push({x, y});
    st[x][y] = 1;
    pre[x][y] = {0, 0};
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.fi + dx[i], b = t.se + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= n)
                continue;
            if (st[a][b])
                continue;
            if (g[a][b] == 0)
            {
                q.push({a, b});
                st[a][b] = 1;
                pre[a][b] = t;
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    bfs(n - 1, n - 1);
    PII t = {0, 0};
    while (1)
    {
        cout << t.fi << " " << t.se << endl;
        if (t.fi == n - 1 && t.se == n - 1)
            break;
        t = pre[t.fi][t.se];
    }
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
