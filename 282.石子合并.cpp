#include <bits/stdc++.h> //区间dp
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const int N = 310;
int n;
int f[N][N]; // 从i到j这一段石子合并的成一堆的最小代价
int w[N];
int s[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		s[i] = s[i - 1] + w[i];
	}
	memset(f, 0x3f, sizeof f); // 区间dp模板
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++) // 左边界
		{
			int j = i + len - 1; // 右边界
			if (len == 1)
			{
				f[i][j] = 0;
				continue;
			}
			for (int k = i; k + 1 <= j; k++) // 枚举分割点
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	}
	cout << f[1][n] << endl;
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
