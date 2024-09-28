#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> PII;
const int N = 70, M = 32010;
int f[M];
int n, m;
vector<PII> a[N]; // 主件
vector<PII> b[N]; // 附件
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int v, p, q;
        cin >> v >> p >> q;
        if (!q)
            a[i].push_back({v, v * p});
        else
            b[q].push_back({v, v * p});
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto it : b[i]) // 枚举所有附件
        {
            int v = it.fi, w = it.se;
            int len = a[i].size();
            for (int j = 0; j < len; j++) // 选择所有不同主附件打包方案进行打包存主件中
            {
                a[i].push_back({a[i][j].fi + v, a[i][j].se + w});
            }
        }
    }
    // 分组背包模板
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 0; k < a[i].size(); k++)
                if (j >= a[i][k].fi)
                    f[j] = max(f[j], f[j - a[i][k].fi] + a[i][k].se);
    cout << f[m] << endl;
    return 0;
}
