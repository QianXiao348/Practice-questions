#include<bits/stdc++.h>//树型dp +背包 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 310;
int e[N],h[N],ne[N],idx;
int f[N][N];
int w[N];
int n,m;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u){
	for(int i=h[u];~i;i=ne[i]){//物品 
		int son=e[i];
		dfs(son);
		//分组背包 
		for(int j=m-1;j>0;j--){//体积  将父节点的位置空出来 
			for(int k=0;k<=j;k++){
				f[u][j]=max(f[u][j],f[u][j-k]+f[son][k]);
			} 
		}
	}
	for(int i=m;i;i--){//将前面空出的父节点进行填补上 
		f[u][i]=f[u][i-1]+w[u];
	} 
}
void solve(){
	cin>>n>>m;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++){
		int p;
		cin>>p>>w[i];
		add(p,i);
	}
	m++;//由于建立了虚拟源点0  所以总节点数+1； 
	dfs(0);
	cout<<f[0][m]<<endl;
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


