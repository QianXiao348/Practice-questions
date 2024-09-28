#include <bits/stdc++.h>//记忆化搜索 (区间dp) 
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const double INF = 1e9;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const int N = 15, M = 9;
int n, m = 8;
int s[N][N];
double f[M][M][M][M][N];//将子矩阵(x1,y1)(x2,y2)切分成k部分的所有方案 
double X;
double get(int x1, int y1, int x2, int y2)
{
	double sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] - X;
	return sum * sum / n;
}
double dp(int x1, int y1, int x2, int y2, int k)
{
	double &v = f[x1][y1][x2][y2][k];
	if (v >= 0)
		return v;
	if (k == 1) // 只有1部分没法切
		return v = get(x1, y1, x2, y2);
	v = INF;
	for (int i = x1; i < x2; i++) // 横切
	{
		v = min(v, dp(x1, y1, i, y2, k - 1) + get(i + 1, y1, x2, y2)); // 选上面
		v = min(v, dp(i + 1, y1, x2, y2, k - 1) + get(x1, y1, i, y2)); // 选下面
	}
	for (int i = y1; i < y2; i++) // 竖切
	{
		v = min(v, dp(x1, y1, x2, i, k - 1) + get(x1, i + 1, x2, y2)); // 选左面
		v = min(v, dp(x1, i + 1, x2, y2, k - 1) + get(x1, y1, x2, i)); // 选右面
	}
	return v;
}
int main()
{
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
	// 	PASE;
	cin >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> s[i][j];
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	memset(f, -1, sizeof f);
	X = (double)s[m][m] / n;//平均值 
	printf("%.3lf\n", sqrt(dp(1, 1, 8, 8, n)));
	return 0;
}
