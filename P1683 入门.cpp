#include<bits/stdc++.h>
using namespace std;
int w,h,ans=0;
char ch[25][25];
bool st[25][25];
int dx[]={-1,0,1,0};//����4������ 
int dy[]={0,1,0,-1};
void dfs(int x,int y){
   for(int i=0;i<4;i++){
   	int a=x+dx[i],b=y+dy[i];
   	if(a<0||a>=h||b<0||b>=w)
   	 continue;//����Խ�� 
   	 if(ch[a][b]!='.')  continue;//��������ϲ���¼ 
      if(st[a][b]) continue;//����Ѿ��߹�Ҳ����¼ 
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
      	st[i][j]=true;//����ʼλ�ü�¼ 
      	x=i,y=j;
      	ans++;
	  }
     }    
   }
    dfs(x,y);
    cout<<ans;
	return 0;
}

