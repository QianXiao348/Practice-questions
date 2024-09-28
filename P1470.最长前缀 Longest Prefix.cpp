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
const int MOD = 10000007;
const double eps = 1e-8;
const int N = 2e5 + 10;
int n, m;
int f[N];
set<string> s[20];
void solve()
{
    string c;
    while (cin >> c)
    {
        if (c == ".")
            break;
        s[c.size()].insert(c);
        m = max(m, int(c.size()));
    }
    string n;
    n = " ";
    f[0] = 1;
    int res = 0;
    while (cin >> c)
    {
        n = n + c;
    }
    for (int i = 1; i < n.size(); i++)
    {
        for (int j = min(i, m); j; j--)
        {
            string tt = n.substr(i - j + 1, j);
            if (s[tt.size()].count(tt) == 1 && f[i - j] == 1)
            {
                res = i;
                f[i] = 1;
                break;
            }
        }
    }
    cout << res << endl;
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
