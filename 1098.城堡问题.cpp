#include <bits/stdc++.h>//Flood Fill
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {0, -1, 0, 1};// 西北东南 1 2 4 8 二进制位运算
const int dy[] = {-1, 0, 1, 0};
const int INF = 0x3f3f3f3f;
const int MOD = 1e6 + 7;
const double eps = 1e-8;
const int N = 1010;
int n, m;
int g[N][N];
bool st[N][N];
int bfs(int x, int y)
{
    queue<PII>q;
    q.push({x, y});
    st[x][y] = 1;
    int sum = 1;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.fi + dx[i], b = t.se + dy[i];
            if (a < 1 || b < 1 || a > n || b > m)
                continue;
            if (st[a][b])
                continue;
            if (g[t.fi][t.se] >> i & 1)// 前进的方向上有墙
                continue;
            q.push({a, b});
            st[a][b] = 1;
            sum++;
        }
    }
    return sum;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    int area = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!st[i][j])
            {
                area = max(area, bfs(i, j));
                cnt++;
            }
    cout << cnt << endl;
    cout << area << endl;
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
