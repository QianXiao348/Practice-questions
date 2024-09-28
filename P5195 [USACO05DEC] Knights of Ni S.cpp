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
const int N = 1010;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int n,m;
int cnt;
int g[N][N];
int sx,sy,ex,ey;
int dist[2][N][N];
vector<PII>xy;
void bfs(int s_x,int s_y,int k){
	memset(dist[k],0x3f,sizeof dist[k]);
	queue<PII>q;
	q.push({s_x,s_y});
	dist[k][s_x][s_y]=0;
	while(q.size()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.fi+dx[i],b=t.se+dy[i];
			if(a>0&&a<=n&&b>0&&b<=m&&dist[k][a][b]==0x3f3f3f3f&&g[a][b]!=1){
				dist[k][a][b]=dist[k][t.fi][t.se]+1;
				q.push({a,b});
			}
		}
	}
}
int main()
{
	FASE;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
			if(g[i][j]==2)
				sx=i,sy=j;
			if(g[i][j]==3)
				ex=i,ey=j;
			if(g[i][j]==4)
				xy.push_back({i,j});
		}
	g[ex][ey]=1;
	bfs(sx,sy,0);
	g[ex][ey]=3;
	bfs(ex,ey,1);
	LL ans=LLONG_MAX,res;
	for(int i=0;i<xy.size();i++){
		res=dist[0][xy[i].fi][xy[i].se]+dist[1][xy[i].fi][xy[i].se];
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}

