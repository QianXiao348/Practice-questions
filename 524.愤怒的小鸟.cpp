#include <bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<double, double> PDD;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const int N = 18, M = 1 << 18;
int n, m;
PDD pig[N];
int path[N][N]; // path[i][j]:第i只和第j只小猪构成的抛物线能覆盖的所有状态(是一个状态压缩值，比如0101=5)
int f[M];		// f[i]表示覆盖掉目前i的状态表示中所有小猪，最少需要多少条抛物线，也就是最少需要多少只小鸟
int check(double a, double b)
{
	return abs(a - b) < eps;
}
void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)// 因为采用状压DP，下标从0开始
		cin >> pig[i].fi >> pig[i].se;
	memset(path, 0, sizeof path);
	for (int i = 0; i < n; i++)// 枚举第一只小猪
	{
		path[i][i] = 1 << i;//抛物线必经过i号小猪
		for (int j = i + 1; j < n; j++) // j从i+1开始，防止出现重复，比如(1,3)和(3,1)其实是同一条抛物线
		{
			double x1 = pig[i].fi, y1 = pig[i].se;
			double x2 = pig[j].fi, y2 = pig[j].se;
			if (check(x1, x2))//一条抛物线不能经过上下垂直小猪
				continue;
			double a = (y1 / x1 - y2 / x2) / (x1 - x2);//根据计算求抛物线a，b
			double b = (y1 / x1) - a * x1;
			if (a >= 0) // 抛物线开口需要向下
				continue;
			for (int k = 0; k < n; k++)// 此抛物线可以覆盖掉哪些小猪
			{
				double x = pig[k].fi, y = pig[k].se;
				if (check(a * x * x + b * x, y))
					path[i][j] += 1 << k; // 记录此抛物线方程覆盖掉k号小猪
			}
		}
	}
	memset(f, 0x3f, sizeof f);// 预求最小，先设最大,表示状态不合法或没有计算过
	f[0] = 0; // 递推起点，一只小猪也不覆盖掉，需要0条抛物线，这在现实中是合理的解释
/*枚举每个存在0的状态,　(1<<n)-1类似于 111111这样的形式，
因为现在的目标是找出含有数位是0的状态进行状态转移，所以全是1的不用考虑*/
	for (int x = 0; x < (1 << n) - 1; x++)
	{
		if (f[x] == 0x3f3f3f3f)
			continue;
		for (int i = 0; i < n; i++)
		{// 枚举状态x的每一个数位，也可以理解为每一只小猪，看看它是不是还没有被覆盖到
			if ((x >> i & 1) == 0)// i号小猪现在还没有被覆盖到
			{
				for (int j = 0; j < n; j++)// 枚举i号小猪参与的所有抛物线
				{
					if (path[i][j])// 引入此抛物线(i,j)，可以在x状态基础上覆盖掉更多的小猪，到达k状态
					{
						int k = path[i][j] | x;// 记录k状态是通过x状态在增加一条抛物线的代价下到达的
						f[k] = min(f[k], f[x] + 1);
					}
				}
				break;
			}
		}
	}
	cout << f[(1 << n) - 1] << endl;// 递推的结果保存在所有状态都是1的结果数组中
}
int main()
{
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
	PASE;
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
