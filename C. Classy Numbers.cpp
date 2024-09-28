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
const int N = 32;
LL f[N][N];
int al, a[N];
LL l, r;

LL dfs(int u, int st, bool op)
{
    if (!u)
        return 1;
    if (!op && ~f[u][st])
        return f[u][st];
    int up = op ? a[u] : 9;
    LL res = 0;
    for (int i = 0; i <= up; i++)
    {
        if (i && st >= 3)
            continue;
        res += dfs(u - 1, st + (i!=0), op && i == up);
    }
    if (!op)
        f[u][st] = res;
    return res;
}
LL calc(LL n)
{
    al = 0;
    while (n)
        a[++al] = n % 10, n /= 10;
    return dfs(al, 0, true);
}
void solve()
{
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;
}
int main()
{
    //freopen("in.txt", "rt", stdin);
    //freopen("out.txt", "wt", stdout);
    PASE;
    memset(f,-1,sizeof f);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
