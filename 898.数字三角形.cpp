#include <bits/stdc++.h>
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
const int N = 510;
int n;
int a[N][N];
int f[N][N];

int main()
{
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
	PASE;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	memset(f, -0x3f, sizeof f);
	f[1][1] = a[1][1];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = max(f[i - 1][j] + a[i][j], f[i - 1][j - 1] + a[i][j]);
	cout << *max_element(f[n] + 1, f[n] + n + 1);

	return 0;
}
