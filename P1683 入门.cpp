#include<bits/stdc++.h>
using namespace std;
int w,h,ans=0;
char ch[25][25];
bool st[25][25];
int dx[]={-1,0,1,0};//代表4个方向 
int dy[]={0,1,0,-1};
void dfs(int x,int y){
   for(int i=0;i<4;i++){
   	int a=x+dx[i],b=y+dy[i];
   	if(a<0||a>=h||b<0||b>=w)
   	 continue;//不能越界 
   	 if(ch[a][b]!='.')  continue;//如果不符合不记录 
      if(st[a][b]) continue;//如果已经走过也不记录 
      st[a][b]=true;
      ans++;
      dfs(a,b);
   }
} 
int main(){
   cin>>w>>h;
   int x,y;
  for(int i=0;i<h;i++){
     for(int j=0;j<w;j++){
     cin>>ch[i][j];
      if(ch[i][j]=='@'){
      	st[i][j]=true;//将开始位置记录 
      	x=i,y=j;
      	ans++;
	  }
     }    
   }
    dfs(x,y);
    cout<<ans;
	return 0;
}

