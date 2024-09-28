#include <bits/stdc++.h> //01±³°ü 
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
const int N = 2010;
int n, m;
LL f[N];
int w[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= min(w[i], j); k++)
                f[j] = (f[j] + f[j - k]) % MOD;
    }
    cout << f[m];
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
