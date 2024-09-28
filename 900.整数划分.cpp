#include <bits/stdc++.h>//完全背包+恰好 
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
const int N = 1010;
int n;
int f[N];
void solve()
{
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
			f[j] = (f[j] + f[j - i]) % MOD;
	}
	cout << f[n];
}
int main()
{
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
	PASE;
	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
