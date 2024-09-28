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
const int MOD = 10000007;
const double eps = 1e-8;
const int N = 64;
LL f[11][N][2050];
int al, a[N];
LL l, r;
int b;

LL dfs(int u, LL st, bool lead, bool op)
{
    if (!u)
        return !st;
    if (!op && !lead && ~f[b][u][st])
        return f[b][u][st];
    int up = op ? a[u] : b - 1;
    LL res = 0;
    for (int i = 0; i <= up; i++)
    {
        if (lead && i == 0)
            res += dfs(u - 1, st, lead && i == 0, op && i == up);
        else
            res += dfs(u - 1, st ^ (1 << i), lead && i == 0, op && i == up);
    }
    if (!op && !lead)
        f[b][u][st] = res;
    return res;
}
LL calc(LL n)
{
    al = 0;
    while (n)
        a[++al] = n % b, n /= b;
    return dfs(al, 0, true, true);
}
void solve()
{
    cin >> b >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;
}
int main()
{
    // freopen("in.txt", "rt", stdin);
    // freopen("out.txt", "wt", stdout);
    PASE;
    memset(f, -1, sizeof f);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
