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
const int N = 400 + 10;
int n, m1, m2;
int f[N][N];
void solve()
{
    cin >> m1 >> m2 >> n;
    for(int i = 1; i <= n; i++)
    {
        int h, t, k;
        cin >> h >> t >> k;
        for (int j = m1; j >= h; j--)
            for (int p = m2; p >= t; p--)
                f[j][p] = max(f[j][p], f[j - h][p - t] + k);
    }
    cout << f[m1][m2] << endl;
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
