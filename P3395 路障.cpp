#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
queue<pair<int,int>>q;
int T,n;
int use[1105][1105];
int dist[1105][1105];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool bfs(int sx,int sy){
	memset(dist,-1,sizeof dist);
	q.push({sx,sy});
    dist[sx][sy]=0;
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		if(t.x==n&&t.y==n){
			return true;
		}
		for(int i=0;i<4;i++){
			int a=t.x+dx[i],b=t.y+dy[i];
			if(a<1||b<1||a>n||b>n) continue;
			if(dist[a][b]>=0||dist[t.x][t.y]>=use[a][b]) continue;
			q.push({a,b});
			dist[a][b]=dist[t.x][t.y]+1;
			if(a==n&&b==n)
			 return true;
		}
	}
	return false;
}
int main(){
    cin>>T;
    while(T--){
    	memset(use,0x3f,sizeof use);
    	cin>>n;
    	for(int i=0,j=2;i<2*n-2;i++,j++){
    		int nx,ny;
    		cin>>nx>>ny;
    		use[nx][ny]=min(j,use[nx][ny]);
		}
		if(bfs(1,1))
		 cout<<"Yes"<<endl;
		 else
		  cout<<"No"<<endl;
		while(!q.empty()){
			q.pop();
		}
	}
	return 0;
}
