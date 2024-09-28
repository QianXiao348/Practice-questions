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
int n,m,t1;
char g[N][N];
int sx,sy,ex,ey;
int dis[N][N][20];
//struct Node{
//	int x,y,z;
//};
//void bfs(){
//	queue<Node>q;
//	q.push({sx,sy,0});
//	dis[sx][sy][0]=1;
//	while(q.size()){
//		auto t=q.front();
//		q.pop();
//		for(int i=0;i<4;i++){
//			int a=t.x+dx[i],b=t.y+dy[i],c=t.z+1;
//			if(a<1||b<1||a>n||b>m||g[a][b]=='*'||c>t1) continue;
//			if(dis[a][b][c]){//避免重复扩展进行剪枝 
//				dis[a][b][c]+=dis[t.x][t.y][t.z];
//				continue;
//			}
//			dis[a][b][c]+=dis[t.x][t.y][t.z];
//			q.push({a,b,c});
//		}
//	}
//}

int dfs(int x,int y,int t){ //记忆化搜索 
	if(dis[x][y][t]!=-1) return dis[x][y][t];
	if(t>t1) return dis[x][y][t]=0;
	if(abs(x-ex)+abs(y-ey)>t1-t) return dis[x][y][t]=0;
	if(t==t1){
		if(x==ex&&y==ey) return dis[x][y][t]=1;
		else dis[x][y][t]=0;
	}
	int ans=0;
	for(int i=0;i<4;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<1||b<1||a>n||b>m||g[a][b]=='*') continue;
		ans+=dfs(a,b,t+1);
	}
	return dis[x][y][t]=ans;
}

int main()
{
	FASE;
	cin>>n>>m>>t1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>g[i][j];
	cin>>sx>>sy>>ex>>ey;
//	bfs();
//	cout<<dis[ex][ey][t1];

	memset(dis,-1,sizeof dis);
	cout<<dfs(sx,sy,0);
	return 0;
}

