#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
queue<pair<int,int>>q;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char ch[510][510];
bool use[510][510];
int n,m,ans=0;
void bfs(int sx,int sy){
	q.push({sx,sy});
	use[sx][sy]=true;
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.x+dx[i],b=t.y+dy[i];
			if(a<0||a>n+1||b<0||b>m+1) continue;
			if(use[a][b]||ch[a][b]=='*') continue;
			q.push({a,b});
			use[a][b]=true;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>ch[i][j];
	 bfs(0,0);
	 for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    if(ch[i][j]=='0'&&!use[i][j]){
	    	ans++;
		}
	cout<<ans<<endl;
	return 0;
}

