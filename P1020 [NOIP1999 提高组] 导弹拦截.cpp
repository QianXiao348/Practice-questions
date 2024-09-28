#include <bits/stdc++.h>
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
const int N = 1e5 + 10;
int n = 1, a[N];
int f[N], fl;
int g[N], gl;

void solve()
{
    while (cin >> a[n])
        n++;
    n--;
    f[++fl] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (f[fl] >= a[i])
            f[++fl] = a[i];
        else
            *upper_bound(f + 1, f + fl + 1, a[i],greater<int>()) = a[i];//greater<int>() 来实现相反的查找顺序。
    }
    g[++gl] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (g[gl] < a[i])
            g[++gl] = a[i];
        else
            *lower_bound(g + 1, g + gl + 1, a[i]) = a[i];
    }
    cout << fl << endl;
    cout << gl;
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
