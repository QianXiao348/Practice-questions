#include <bits/stdc++.h> //线性dp（数字三角形模型） 
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
const int N = 110;
int n;
int w[N][N];
int f[N][N];

int main()
{
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
	PASE;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> w[i][j];
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
		f[i][0] = f[0][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == 1)
				f[i][j] = f[i][j - 1] + w[i][j];
			else if (j == 1)
				f[i][j] = f[i - 1][j] + w[i][j];
			else
				f[i][j] = min(f[i - 1][j], f[i][j - 1]) + w[i][j];
		}
	cout << f[n][n] << endl;

	return 0;
}

