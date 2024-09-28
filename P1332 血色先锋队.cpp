#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int n,m,a,b,ex,ey;
int dist[510][510];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
queue<pair<int,int>>q;
void bfs(){
     while(!q.empty()){
     	auto t=q.front();
     	q.pop();
     	for(int i=0;i<4;i++){
     		int a=t.x+dx[i],b=t.y+dy[i];
     		if(a<1||b>n||b<1||b>m) continue;
     		if(dist[a][b]>=0) continue;
     		 q.push({a,b});
			 dist[a][b]=dist[t.x][t.y]+1; 
		 }
	 }
	
}
int main(){
	memset(dist,-1,sizeof dist);
     cin>>n>>m>>a>>b;
     for(int i=0;i<a;i++){
     	int sx,sy;
     	cin>>sx>>sy;
     	q.push({sx,sy});
     	dist[sx][sy]=0;
	 }
	 bfs();
	 for(int i=0;i<b;i++){
	 	cin>>ex>>ey;
	 	cout<<dist[ex][ey]<<endl;
	 }
	return 0;
}

