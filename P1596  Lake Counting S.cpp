#include<bits/stdc++.h>
using namespace std;
const int N= 110;
int n,m,ans=0;
char ch[N][N];
bool st[N][N];//��ʾ��û\û����û�� 
int dx[]={-1,-1,0,1,1,1,0,-1};//����8������ 
int dy[]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<0||a>=n||b<0||b>=m) continue;
		if(ch[a][b]!='W') continue;
		if(st[a][b]) continue;//���͹� 
		st[a][b]=true;//�߹��������
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

