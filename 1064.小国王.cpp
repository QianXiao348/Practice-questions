#include <bits/stdc++.h> //״ѹdp
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
LL f[N][K][M];       // ��ʾǰi���Ѿ����꣬������j������������ ��i��״̬��k�����з�����
int cnt[M];          // ��¼ÿ��״̬�е�����1����
vector<int> state;   // ���кϷ���״̬��Ԥ����Ľ����
vector<int> head[M]; // ÿ��״̬���п���ת�Ƶ�������״̬
bool check(int x)   // ������2��������1
{
	return !(x & x >> 1);
}
int count(int x)
{
	// 1�ĸ���
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
	// ö�����з���
	for (int i = 0; i < 1 << n; i++)
	{
		if (check(i)) // ͬһ�в���������1
		{
			state.push_back(i);
			cnt[i] = count(i);
		}
	}
	// ö��������״̬
	for (auto a : state)
	{
		for (auto b : state)
		{
			if ((a & b) == 0 && check(a | b)) // �����У�45��˫�ؼ��
				head[a].push_back(b);         // ��¼�Ϸ���״̬ת�ƹ�ϵ
		}
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		// ö��ÿһ��
		for (int j = 0; j <= m; j++)
		{
			// ö�ٹ�������
			for (auto a : state)
			{
				// ö�ٵ�i�е�ÿһ�ֿ���״̬
				for (auto b : head[a])
				{
					// a״̬�����кϷ�ǰ��״̬
					int c = cnt[a]; // ״̬a�Ĺ�������
					if (j >= c)
						f[i][j][a] += f[i - 1][j - c][b];
				}
			}
		}
	}
	LL res = 0;
	// �������n��֮�󣬽�m���������꣬ÿһ���Ϸ�״̬���ǿ��ܵĽ⣬�ۼ������Ǵ�
	for (auto a : state)
		res += f[n][m][a];
	cout << res << endl;
	return 0;
}

