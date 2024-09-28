#include <bits/stdc++.h> //线性DP+费用提前计算思想/ 
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
const int N = 5000 + 10;
int n, s;
LL f[N]; // 将前i个任务处理完的所有方案
LL sumt[N], sumc[N];
void solve()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> sumt[i] >> sumc[i];
        sumt[i] += sumt[i - 1];
        sumc[i] += sumc[i - 1];
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] = min(f[i], f[j] + sumt[i] * (sumc[i] - sumc[j]) + s * (sumc[n] - sumc[j]));
        }
    }
    cout << f[n] << endl;
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
