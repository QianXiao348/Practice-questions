#include <bits/stdc++.h> //单调队列优化dp
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
const int N = 2e6 + 10;
int n;
int p[N], d[N];
LL s[N];//从1号节点出发，到达i号节点，还未取得i号节点的油量前，剩余油量
int q[N], hh, tt;
bool ans[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> d[i];
        p[i + n] = p[i], d[i + n] = d[i];
    }
    for (int i = 1; i <= n * 2; i++)
        s[i] = s[i - 1] + p[i - 1] - d[i - 1];
    hh = 0, tt = -1;
    q[++tt] = n * 2 + 1;//哨兵 
    for (int i = n * 2; i; i--)
    {
        while (hh <= tt && q[hh] - i > n)
            hh++;
        if (s[q[hh]] >= s[i])
            ans[i] = true;
        while (hh <= tt && s[q[tt]] >= s[i])
            tt--;
        q[++tt] = i;
    }
    hh = 0, tt = -1;
    q[++tt] = 0;
    for (int i = n * 2; i; i--)
        s[i] = s[i + 1] + p[i + 1] - d[i];
    for (int i = 1; i <= 2 * n; i++)
    {
        while (hh <= tt && i - q[hh] > n)
            hh++;
        if (s[q[hh]] >= s[i])
            ans[i - n] = true;
        while (hh <= tt && s[q[tt]] >= s[i])
            tt--;
        q[++tt] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << (ans[i] ? "TAK" : "NIE") << endl;
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
