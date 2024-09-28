#include <bits/stdc++.h>// ����dp 
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
const int N = 40;
int n;
int w[N];
int f[N][N];		   // DP���� : i,j�����ڵ����÷�
int g[N][N];		   // ·�����飺i,j�����ڵ����÷֣�����k����ڵ�Ϊ��������»�õ�
void dfs(int l, int r) // ǰ�����
{
	if (l > r)
		return;
	int root = g[l][r];
	cout << root << " ";
	dfs(l, root - 1);
	dfs(root + 1, r);
}
int main()
{
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
	PASE;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			if (len == 1) // û���������Ǳ��� 
			{
				f[i][j] = w[i];
				g[i][j] = i;
			}
			else
			{ // ö�ٸ��ڵ�k, �������䣺[l,k-1],[k+1,r],���ڵ�kҲռ��һ��λ��
				for (int k = i; k <= j; k++)
				{
					int left = k == i ? 1 : f[i][k - 1];  // ������Ϊ�գ�����1
					int right = k == j ? 1 : f[k + 1][j]; // ������Ϊ�գ�����1
					int score = left * right + w[k];
					if (f[i][j] < score)
					{
						f[i][j] = score;
						g[i][j] = k;
					}
				}
			}
		}
	}
	cout << f[1][n] << endl;
	dfs(1, n);
	return 0;
}
