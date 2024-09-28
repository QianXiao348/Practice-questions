#include <bits/stdc++.h> //ÊýÎ»dp
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
const int N = 32;
int f[N][N];
int l, r;
int al, a[N];
int dfs(int u, int st, bool op)
{
    if (!u)
        return 1;
    if (!op && ~f[u][st])
        return f[u][st];
    int up = op ? a[u] : 9;
    int res = 0;
    for (int i = 0; i <= up; i++)
    {
        if (i == 4 || (st == 6 && i == 2))
            continue;
        res += dfs(u - 1, i, op && i == a[u]);
    }
    if (!op)
        f[u][st] = res;
    return res;
}
int calc(int n)
{
    al = 0;
    while (n)
        a[++al] = n % 10, n /= 10;
    return dfs(al, -2, true);
}
void solve()
{
    while (cin >> l >> r, l || r)
    {
        memset(f, -1, sizeof f);
        cout << calc(r) - calc(l - 1) << endl;
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
