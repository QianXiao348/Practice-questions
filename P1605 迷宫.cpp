#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,fx,fy,nx,ny;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int ans=0;
int chess[12][12];
void dfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return;
	}
	for(int i=0;i<4;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<0||a>m||b<0||b>n) continue;
		if(chess[a][b]){
			chess[a][b]=0;
			dfs(a,b);
			chess[a][b]=1;//回溯 
		}
		
	}
}
int main(){
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
  for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
			chess[i][j]=1;//构造棋盘 
		}
	}
    for(int i=0;i<t;i++){
    	cin>>nx>>ny;
    	chess[nx][ny]=0;
	}
	chess[sx][sy]=0;//起点标记不可访问 
    dfs(sx,sy);
    cout<<ans;
	return 0;
}

