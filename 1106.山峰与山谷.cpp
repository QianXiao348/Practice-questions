#include <bits/stdc++.h> //[Flood Fill,∂‡∑µªÿ÷µ]
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
void bfs(int x, int y, bool &has_f, bool &has_g)
{
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int a = t.fi + dx[i], b = t.se + dy[i];
            if (a < 1 || b < 1 || a > n || b > n)
                continue;
            if (g[a][b] != g[t.fi][t.se])
            {
                if (g[a][b] > g[t.fi][t.se])
                    has_f = true;
                else
                    has_g = true;
            }
            else if (!st[a][b])
            {
                q.push({a, b});
                st[a][b] = true;
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    int sf = 0, sg = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (!st[i][j])
            {
                bool has_f = false, has_g = false;
                bfs(i, j, has_f, has_g);
                if (!has_f)
                    sf++;
                if (!has_g)
                    sg++;
            }
        }
    cout << sf << " " << sg << endl;
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
