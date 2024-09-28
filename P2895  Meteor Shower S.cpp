#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
queue<pair<int,int>>q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n;
int use[305][305];
int dist[305][305];
int bfs(int sx,int sy){
	q.push({sx,sy});
    dist[sx][sy]=0;
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.x+dx[i],b=t.y+dy[i];
			if(a<0||b<0||a>301||b>301) continue;//注意右边界可以没有限制 
			if(dist[a][b]||dist[t.x][t.y]+1>=use[a][b]) continue;
			q.push({a,b});
			dist[a][b]=dist[t.x][t.y]+1;
			if(use[a][b]==0x3f3f3f3f)
			 return dist[a][b];
		}
	}
	return -1;
}
int main(){
	memset(use,0x3f,sizeof use);
    cin>>n;
    for(int i=0;i<n;i++){
    	int tx,ty,tt;
    	cin>>tx>>ty>>tt;
    	use[tx][ty]=min(tt,use[tx][ty]);
    	for(int i=0;i<4;i++){
    		int a=tx+dx[i],b=ty+dy[i];
    		if(a<0||b<0||a>301||b>301) continue;
    		use[a][b]=min(tt,use[a][b]);
		}
	}
	cout<<bfs(0,0);
	return 0;
}
