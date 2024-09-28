#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
queue<pair<int,int>>q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n,m,nx,ny;
char ch[2005][2005];
int dist[2005][2005];
void bfs(int sx,int sy){
	q.push({sx,sy});
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.x+dx[i],b=t.y+dy[i];
			if(a<1||a>n||b<1||b>m) continue;
			if(dist[a][b]>=1||ch[a][b]=='#') continue;
			q.push({a,b});
			dist[a][b]=dist[t.x][t.y]+1;
			if(a==nx&&b==ny){
			cout<< dist[a][b];
			return;
			}
			 
		}
	}
	cout<<"No Way!";
}
int main(){
	int sx,sy;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++){
     	cin>>ch[i][j];
     	if(ch[i][j]=='d')
     	 nx=i,ny=j;
     	if(ch[i][j]=='m')
     	 sx=i,sy=j;
	 }
	bfs(sx,sy);
	return 0;
}
