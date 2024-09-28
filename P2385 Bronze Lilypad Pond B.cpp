#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int m,n,m1,m2,endx,endy;
int dist[35][35];
int chess[35][35];
int dx[9];
int dy[9];
queue<pair<int,int>>q;
int bfs(int sx,int sy){
	memset(dist,-1,sizeof dist);
	q.push({sx,sy});
	dist[sx][sy]=0;
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		for(int i=1;i<=8;i++){
			int a=t.x+dx[i],b=t.y+dy[i];
			if(a<1||a>m||b<1||b>n) continue;
			if(dist[a][b]>=0||chess[a][b]==2||chess[a][b]==0) continue;
			q.push({a,b});
			dist[a][b]=dist[t.x][t.y]+1;
			if(a==endx&&b==endy)
			 return dist[a][b];
		}
	}
} 
int main(){
	int sx,sy;
    cin>>m>>n>>m1>>m2;
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		cin>>chess[i][j];
    		if(chess[i][j]==3)
    		 sx=i,sy=j;
    		if(chess[i][j]==4)
    		 endx=i,endy=j;
		}
	}
  dx[1]=m2,dy[1]=m1;
	dx[2]=m2,dy[2]=-m1;
	dx[3]=-m2,dy[3]=-m1;
	dx[4]=-m2,dy[4]=m1;
	dx[5]=m1,dy[5]=m2;
	dx[6]=m1,dy[6]=-m2;
	dx[7]=-m1,dy[7]=-m2;
	dx[8]=-m1,dy[8]=m2;
	cout<<bfs(sx,sy);
	return 0;
}

