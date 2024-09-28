#include<bits/stdc++.h>
using namespace std;
#define FASE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const double PI = 3.1415926;
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 110;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n,m;
int hight[N][N];
int ans;
int vis[N][N];
int dfs(int x,int y){
	if(vis[x][y]) //若是进行有结果直接返回结果 
		return vis[x][y];
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int a=x+dx[i],b=y+dy[i];
		if(hight[a][b]<hight[x][y]&&a>0&&b>0&&a<=n&&b<=m){
			vis[x][y]=max(vis[x][y],dfs(a,b)+1);
		}
	}
	return vis[x][y];
}
int main()
{
	FASE;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>hight[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			ans=max(ans,dfs(i,j));
		}
	cout<<ans;
	return 0;
}

