#include<bits/stdc++.h>
using namespace std;
const int N= 110;
int n,m,ans=0;
char ch[N][N];
bool st[N][N];//表示淹没\没有淹没过 
int dx[]={-1,-1,0,1,1,1,0,-1};//代表8个方向 
int dy[]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<0||a>=n||b<0||b>=m) continue;
		if(ch[a][b]!='W') continue;
		if(st[a][b]) continue;//被淹过 
		st[a][b]=true;//走过的作标记
		dfs(a,b);
	} 
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    	scanf("%s",ch[i]);
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(ch[i][j]=='W'&&st[i][j]==false){
    			dfs(i,j);
    			ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}

