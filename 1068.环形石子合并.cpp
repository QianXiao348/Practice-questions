#include <bits/stdc++.h> //����dp
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
const int N = 410;
int n;
int f[N][N]; // ��i��j��һ��ʯ�Ӻϲ��ĳ�һ�ѵ���С����
int g[N][N]; // ��i��j��һ��ʯ�Ӻϲ��ĳ�һ�ѵ�������
int w[N];
int s[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		w[i + n] = w[i];
	}
	for (int i = 1; i <= n * 2; i++)
		s[i] = s[i - 1] + w[i];
	// ����dpģ��	
	memset(f, 0x3f, sizeof f); 
	memset(g, -0x3f, sizeof g);
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n * 2; i++) // ��߽�
		{
			int j = i + len - 1; // �ұ߽�
			if (len == 1)
			{
				f[i][j] = 0;
				g[i][j] = 0;
				continue;
			}
			for (int k = i; k + 1 <= j; k++) // ö�ٷָ��k
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
				g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	}
	int maxv = -0x3f3f3f3f, minv = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		maxv = max(maxv, g[i][i + n - 1]);
		minv = min(minv, f[i][i + n - 1]);
	}
	cout << minv << endl
		 << maxv << endl;
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
