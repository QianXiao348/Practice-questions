#include<bits/stdc++.h>//����dp +���� 
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
	for(int i=h[u];~i;i=ne[i]){//��Ʒ 
		int son=e[i];
		dfs(son);
		//���鱳�� 
		for(int j=m-1;j>0;j--){//���  �����ڵ��λ�ÿճ��� 
			for(int k=0;k<=j;k++){
				f[u][j]=max(f[u][j],f[u][j-k]+f[son][k]);
			} 
		}
	}
	for(int i=m;i;i--){//��ǰ��ճ��ĸ��ڵ������� 
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
	m++;//���ڽ���������Դ��0  �����ܽڵ���+1�� 
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


