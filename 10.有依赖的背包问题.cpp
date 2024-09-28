#include<bits/stdc++.h>  //树形dp + 背包 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 110;
int n,m;
int v[N], w[N];
int h[N], e[N], ne[N], idx;
int f[N][N]; //f[i][j]:选择x为子树，容量不超过j的最大价值 
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u)
{
	for(int i = h[u]; ~i; i = ne[i])
	{
		int son = e[i];
		dfs(son);
		//分组背包 
		for(int j = m-v[u]; j > 0; j --) //将第u件物品腾出来 
			for(int k = 0; k <= j; k++) 
				f[u][j]=max(f[u][j],f[u][j-k]+f[son][k]);
	}
	//加上刚刚默认选择的父节点价值
    for (int j = m; j >= v[u]; -- j) f[u][j] = f[u][j - v[u]] + w[u];
//因为我们是从叶子结点开始往上做，所以如果背包容积不如当前物品的体积大，那就不能选择当前结点及其子节点，因此赋值为零 
    for(int i = 0;i<v[u];i++) f[u][i] = 0;
    
}

void solve(){
	cin >> n >> m;
	int root;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n; i ++)
	{
		int p;
		cin >> v[i] >> w[i] >> p;
		if(p == -1) root = i;
		else add(p, i);
	}
	dfs(root);
	cout << f[root][m] << endl;
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


