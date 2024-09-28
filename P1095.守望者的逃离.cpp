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
const int N = 3e5 + 10;
int m, s, t;
LL f[N]; // 花费i的时间最长路
void solve()
{
    cin >> m >> s >> t;
    f[0] = 0;
    for (int i = 1; i <= t; i++)
    {
        if (m >= 10)
        {
            f[i] = f[i - 1] + 60;
            m -= 10;
        }
        else
        {
            f[i] = f[i - 1];
            m += 4;
        }
    }
    bool flag = false;
    for (int i = 1; i <= t; i++)
    {
        if (f[i] < f[i - 1] + 17)
            f[i] = f[i - 1] + 17;
        if (f[i] >= s)
        {
            cout << "Yes\n"
                 << i;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "No\n"
             << f[t];
}
int main()
{
    // freopen("in.txt", "rt", stdin);
    // freopen("out.txt", "wt", stdout);
    PASE;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
