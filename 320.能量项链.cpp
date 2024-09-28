#include <bits/stdc++.h> //����dp
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
int f[N][N]; // f[i][j]��i��j�����Ӻϲ��ͷŵ��������
int w[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		w[i + n] = w[i];
	}
	// ����dpģ�� 
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
			for (int k = i; k < j; k++)//�м��k
			{
				f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + w[i] * w[k + 1] * w[j + 1]);
			}
			// ����Ĺ���ͬʯ�Ӻϲ������ﲻ���뵽����l��k�����Ӻϲ�֮�����һ������l��βk+1�����ӣ�
            // ͬ������k+1��r�����Ӻϲ�֮�����һ������k+1��βr+1�����ӣ�
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
