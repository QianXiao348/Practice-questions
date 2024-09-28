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
int path[N][N]; // path[i][j]:��iֻ�͵�jֻС���ɵ��������ܸ��ǵ�����״̬(��һ��״̬ѹ��ֵ������0101=5)
int f[M];		// f[i]��ʾ���ǵ�Ŀǰi��״̬��ʾ������С��������Ҫ�����������ߣ�Ҳ����������Ҫ����ֻС��
int check(double a, double b)
{
	return abs(a - b) < eps;
}
void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)// ��Ϊ����״ѹDP���±��0��ʼ
		cin >> pig[i].fi >> pig[i].se;
	memset(path, 0, sizeof path);
	for (int i = 0; i < n; i++)// ö�ٵ�һֻС��
	{
		path[i][i] = 1 << i;//�����߱ؾ���i��С��
		for (int j = i + 1; j < n; j++) // j��i+1��ʼ����ֹ�����ظ�������(1,3)��(3,1)��ʵ��ͬһ��������
		{
			double x1 = pig[i].fi, y1 = pig[i].se;
			double x2 = pig[j].fi, y2 = pig[j].se;
			if (check(x1, x2))//һ�������߲��ܾ������´�ֱС��
				continue;
			double a = (y1 / x1 - y2 / x2) / (x1 - x2);//���ݼ�����������a��b
			double b = (y1 / x1) - a * x1;
			if (a >= 0) // �����߿�����Ҫ����
				continue;
			for (int k = 0; k < n; k++)// �������߿��Ը��ǵ���ЩС��
			{
				double x = pig[k].fi, y = pig[k].se;
				if (check(a * x * x + b * x, y))
					path[i][j] += 1 << k; // ��¼�������߷��̸��ǵ�k��С��
			}
		}
	}
	memset(f, 0x3f, sizeof f);// Ԥ����С���������,��ʾ״̬���Ϸ���û�м����
	f[0] = 0; // ������㣬һֻС��Ҳ�����ǵ�����Ҫ0�������ߣ�������ʵ���Ǻ���Ľ���
/*ö��ÿ������0��״̬,��(1<<n)-1������ 111111��������ʽ��
��Ϊ���ڵ�Ŀ�����ҳ�������λ��0��״̬����״̬ת�ƣ�����ȫ��1�Ĳ��ÿ���*/
	for (int x = 0; x < (1 << n) - 1; x++)
	{
		if (f[x] == 0x3f3f3f3f)
			continue;
		for (int i = 0; i < n; i++)
		{// ö��״̬x��ÿһ����λ��Ҳ�������ΪÿһֻС���������ǲ��ǻ�û�б����ǵ�
			if ((x >> i & 1) == 0)// i��С�����ڻ�û�б����ǵ�
			{
				for (int j = 0; j < n; j++)// ö��i��С����������������
				{
					if (path[i][j])// �����������(i,j)��������x״̬�����ϸ��ǵ������С������k״̬
					{
						int k = path[i][j] | x;// ��¼k״̬��ͨ��x״̬������һ�������ߵĴ����µ����
						f[k] = min(f[k], f[x] + 1);
					}
				}
				break;
			}
		}
	}
	cout << f[(1 << n) - 1] << endl;// ���ƵĽ������������״̬����1�Ľ��������
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
