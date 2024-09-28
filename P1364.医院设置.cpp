#include <bits/stdc++.h> //bfs+ÁÚ½Ó¾ØÕó 
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 1e6 + 7;
const double eps = 1e-8;
const int N = 110;
int d[N][N];
bool st[N];
int n;
int p[N];
int bfs(int x)
{
    memset(st, 0, sizeof(st));
    queue<PII> q;
    q.push({x, 0});
    int sum = 0;
    st[x] = true;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (d[t.fi][i] && !st[i])
            {
                sum += p[i] * (t.se + 1);
                st[i] = true;
                q.push({i, t.se + 1});
            }
        }
    }
    return sum;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> p[i] >> l >> r;
        if (l)
            d[i][l] = d[l][i] = 1;
        if (r)
            d[i][r] = d[r][i] = 1;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
        ans = min(ans, bfs(i));
    cout << ans << endl;
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
