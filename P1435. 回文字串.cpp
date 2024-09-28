#include <bits/stdc++.h>//最长公共子序列 
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
const int N = 1010;
string s;
int f[N][N];
void solve()
{
    cin >> s;
    int n = s.size();
    string s2;
    s2 = s;
    reverse(s2.begin(), s2.end());
    s = " " + s, s2 = " " + s2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (s[i] == s2[j])
                f[i][j] = f[i - 1][j - 1] + 1;
        }
    }
    cout << n - f[n][n] << endl;
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
