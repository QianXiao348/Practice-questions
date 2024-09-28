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
const int N = 2e5 + 10;
int n, m;
int p[N];
int f[N]; // 前1～i座烽火台满足条件，且第i座烽火台 点燃 的方案集合
int q[N], hh, tt;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    hh = 0, tt = -1;
    q[++tt] = 0;
    for (int i = 1; i <= n; i++)
    {
    	//滑动窗口在i左侧，不包括i,使用前序信息可以更新f[i]，滑动窗口长度最长为m
        while (hh <= tt && i - q[hh] > m)
            hh++;
        // 因为i不在滑动窗口中，需要用滑动窗口的内容更新f[i]，在while上方更新
        f[i] = f[q[hh]] + p[i];
        while (hh <= tt && f[q[tt]] >= f[i])
            tt--;
        q[++tt] = i;
    }
    // 答案可能存在于 n-1,n-2,...n-m+1中，枚举一下求最小值即可
    int res = INT_MAX;
    for (int i = n - m + 1; i <= n; i++)
        res = min(res, f[i]);
    cout << res << endl;
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
