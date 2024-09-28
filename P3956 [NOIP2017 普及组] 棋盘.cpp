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
int n,k;
int g[N][N],dist[N][N];
struct Node{
	int sum;
	int x,y;
	bool flag;
	int now;
	bool operator < (const Node &w) const{
		return sum<w.sum;
	}
};
void bfs(){
	memset(dist,0x3f,sizeof dist);
	priority_queue<Node>q;
	q.push({0,1,1,false,g[1][1]});
	dist[1][1]=0;
	while(q.size()){
		auto t=q.top();
		q.pop();
		for(int i=0;i<4;i++){
			auto a=t.x+dx[i],b=t.y+dy[i],d=0;
			if(a<1||b<1||a>n||b>n) continue;
			if(g[a][b]!=t.now){
				if(g[a][b]>0) d=1;
				else if(!t.flag) d=2;
				else continue;
			}
			if(dist[a][b]>dist[t.x][t.y]+d){
				dist[a][b]=dist[t.x][t.y]+d;
				q.push({dist[a][b],a,b,d==2,d==2?t.now:g[a][b]});
			}
		}
	}
}
int main()
{
	FASE;
	cin>>n>>k;
	while(k--){
		int x,y,c;
		cin>>x>>y>>c;
		g[x][y]=c+1;
	}
	bfs();
	if(dist[n][n]==0x3f3f3f3f)
		cout<<"-1"<<endl;
	else cout<<dist[n][n]<<endl;
	return 0;
}

