#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int,int>PII;
int n,m,x,y;
int dist[410][410];
int dx[]={-2,-2,-1,1,2,2,1,-1};
int dy[]={-1,1,2,2,1,-1,-2,-2};
queue<PII>q;
void bfs(int x1,int y1){
	memset(dist,-1,sizeof dist);
	q.push({x1,y1});
	dist[x1][y1]=0;
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int a=t.x+dx[i],b=t.y+dy[i];
			if(a<1||a>n||b<1||b>m) continue;
			if(dist[a][b]>=0) continue;
			q.push({a,b});
			dist[a][b]=dist[t.x][t.y]+1;
		}
	}
}
int main(){
    cin>>n>>m>>x>>y;
	bfs(x,y);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-6d",dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}

