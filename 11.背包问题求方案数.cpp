#include<bits/stdc++.h> 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1010;
int n, m;
int f[N], g[N]; // f[j]、g[j]分别表示体积恰好为j时的最大价值、方案数
void solve(){
	cin >> n >> m;
	memset(f, -0x3f, sizeof f); //空间恰好为j的初始化 
	g[0] = 1;
	f[0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		int v, w;
		cin >> v >> w;
		for(int j = m; j >= v; j--){
			int maxv = max(f[j], f[j-v] + w);
			int cnt = 0;
			if(maxv == f[j]) cnt += g[j];
			if(maxv == f[j-v] + w) cnt += g[j-v];
			g[j] = cnt % MOD;
			f[j] = maxv;
		}
	}
	int res = 0;
	for(int i = 0; i <= m; i ++)
		res = max(res, f[i]);
	int cnt = 0;
	for(int i = 0; i <= m; i ++)
		if(f[i] == res) cnt = (cnt + g[i]) % MOD;
	cout << cnt << endl;
}
int main(){
	PASE;
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}


