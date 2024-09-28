#include <bits/stdc++.h>// 区间dp 
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
int f[N][N];		   // DP数组 : i,j区间内的最大得分
int g[N][N];		   // 路径数组：i,j区间内的最大得分，是在k这个节点为根的情况下获得的
void dfs(int l, int r) // 前序遍历
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
			if (len == 1) // 没有子树就是本身 
			{
				f[i][j] = w[i];
				g[i][j] = i;
			}
			else
			{ // 枚举根节点k, 两个区间：[l,k-1],[k+1,r],根节点k也占了一个位置
				for (int k = i; k <= j; k++)
				{
					int left = k == i ? 1 : f[i][k - 1];  // 左子树为空，返回1
					int right = k == j ? 1 : f[k + 1][j]; // 右子树为空，返回1
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
