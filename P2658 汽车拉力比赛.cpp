#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
queue<pair<int,int>>q;
const int N = 510;
int n,m;
int chess[N][N];
bool flag[N][N];
bool dist[N][N];
int nx,ny,cnt_flag=0;//记录路标开始位置  总数 
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool bfs(int mid){
	q.push({nx,ny});
	dist[nx][ny]=true;
	int cnt_flag_now=1;
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.x+dx[i],b=t.y+dy[i];
			if(a<1||b<1||a>n||b>m) continue;
			if(dist[a][b]) continue;
		if(abs(chess[t.x][t.y]-chess[a][b])>mid) continue;
			q.push({a,b});
			dist[a][b]=true;
			if(flag[a][b]==1){
				 cnt_flag_now++;
				if(cnt_flag_now==cnt_flag)
				return true;
			}
		}	
	}
	return false;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      cin>>chess[i][j];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++){
     	 cin>>flag[i][j];
     	 if(flag[i][j]==1)
     	 cnt_flag++; 
	 }
     for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
      	if(flag[i][j]==1){//找到一个作为开始条件路标 
      		nx=i,ny=j;
      		break;
		  }
	  }
	int l=-1,r=1e9+10;
	while(l<r){
	memset(dist,0,sizeof dist);//每次行走距离初始化 
	while(!q.empty()){//每次搜寻结束清空队列 
		q.pop();
	}
		int mid=l+(r-l)/2;
		if(bfs(mid))
		  r=mid;
		else
		  l=mid+1;
	}
	cout<<r<<endl;
	return 0;
}

