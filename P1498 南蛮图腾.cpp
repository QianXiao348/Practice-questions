#include<bits/stdc++.h>
using namespace std;//��һ������������������ 
char c[2050][2050]; 
void dfs(int x,int y,int n){
	if(n==1){//��ֹ���� 
		c[x][y+1]='/';
		c[x][y+2]='\\';
		c[x+1][y]='/';
		c[x+1][y+1]='_';
		c[x+1][y+2]='_';
		c[x+1][y+3]='\\';
		return;
	}
	int distance=pow(2,n);
	dfs(x,y+distance/2,n-1);//һ��ͼ��ƫ��
	dfs(x+distance/2,y,n-1);//2��ͼ��ƫ��
	dfs(x+distance/2,y+distance,n-1);//3��ͼ��ƫ�� 
}
int main(){
	int n;
	cin>>n;
	memset(c,' ',sizeof(c));
	dfs(0,0,n);
	for(int i=0;i<pow(2,n);i++){
		for(int j=0;j<pow(2,n+1);j++)
	         cout<<c[i][j];
	  cout<<endl;
	}
	return 0;
}
