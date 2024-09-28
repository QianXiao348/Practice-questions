#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
queue<pair<int,int>>q;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool use[35][35];
int n;
int chess[35][35];
void bfs(int sx,int sy){
	q.push({sx,sy});
	use[sx][sy]=true;
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
		int a=t.x+dx[i],b=t.y+dy[i];
		if(a<0||a>n+1||b<0||b>n+1) continue;
		if(use[a][b]||chess[a][b]==1) continue;
		q.push({a,b});
		use[a][b]=true;
	   }
	}	
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  cin>>chess[i][j];
	bfs(0,0);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	 	if(!use[i][j]&&chess[i][j]==0)
	 	 chess[i][j]=2;
    for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
     	cout<<chess[i][j]<<" ";
	 }
	 cout<<endl;
  }
	return 0;
}

