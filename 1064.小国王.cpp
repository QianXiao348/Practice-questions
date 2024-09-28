#include <bits/stdc++.h> //状压dp
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MOD = 1e9 + 7;
const int N = 12, M = 1 << 10, K = 110;
int n, m;
LL f[N][K][M];       // 表示前i行已经摆完，放入了j个国王，并且 第i行状态是k的所有方案。
int cnt[M];          // 记录每种状态中的数字1个数
vector<int> state;   // 所有合法的状态（预处理的结果）
vector<int> head[M]; // 每个状态所有可以转移到的其他状态
bool check(int x)   // 不能有2个连续的1
{
	return !(x & x >> 1);
}
int count(int x)
{
	// 1的个数
	int res = 0;
	while (x)
	{
		x = x & (x - 1);
		res++;
	}
	return res;
}
int main()
{
	PASE;
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	cin >> n >> m;
	// 枚举所有方案
	for (int i = 0; i < 1 << n; i++)
	{
		if (check(i)) // 同一行不能有连续1
		{
			state.push_back(i);
			cnt[i] = count(i);
		}
	}
	// 枚举上下两状态
	for (auto a : state)
	{
		for (auto b : state)
		{
			if ((a & b) == 0 && check(a | b)) // 上下行，45度双重检查
				head[a].push_back(b);         // 记录合法的状态转移关系
		}
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		// 枚举每一行
		for (int j = 0; j <= m; j++)
		{
			// 枚举国王个数
			for (auto a : state)
			{
				// 枚举第i行的每一种可能状态
				for (auto b : head[a])
				{
					// a状态的所有合法前序状态
					int c = cnt[a]; // 状态a的国王数量
					if (j >= c)
						f[i][j][a] += f[i - 1][j - c][b];
				}
			}
		}
	}
	LL res = 0;
	// 在填充完n行之后，将m个国王放完，每一个合法状态都是可能的解，累加起来是答案
	for (auto a : state)
		res += f[n][m][a];
	cout << res << endl;
	return 0;
}

