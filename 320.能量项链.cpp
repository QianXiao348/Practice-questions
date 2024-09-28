#include <bits/stdc++.h> //区间dp
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const int N = 210;
int n;
int f[N][N]; // f[i][j]从i到j个珠子合并释放的最大能量
int w[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		w[i + n] = w[i];
	}
	// 区间dp模板 
	memset(f, -INF, sizeof f);
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n * 2; i++)
		{
			int j = i + len - 1;
			if (len == 1)
			{
				f[i][j] = 0;
				continue;
			}
			for (int k = i; k < j; k++)//中间点k
			{
				f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + w[i] * w[k + 1] * w[j + 1]);
			}
			// 这里的过程同石子合并，这里不难想到若将l到k的珠子合并之后会变成一个首是l而尾k+1的珠子；
            // 同理若将k+1到r的珠子合并之后会变成一个首是k+1而尾r+1的珠子；
		}
	}
	int maxv = -INF;
	for (int i = 1; i <= n; i++)
		maxv = max(maxv, f[i][i + n - 1]);
	cout << maxv << endl;
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
