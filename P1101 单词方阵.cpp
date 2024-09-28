#include<bits/stdc++.h>
using namespace std;
int n;
char ch[105][105]; 
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
string s="yizhong";
int use[105][105];
void search(int x,int y){
	for(int i=0;i<8;i++){
		 int m=1,a,b;
	 for(int j=0;j<s.size();j++){
		 a=x+j*dx[i],b=y+j*dy[i];//对应的8个深度方向 
		if(ch[a][b]!=s[j]){//当不满足直接跳出循环 
			m=0;
			break;
		}
	  }
	  if(m==0) continue;
	  for(int j=0;j<s.size();j++){//当满足时对字符串进行标记 
	  	use[x+j*dx[i]][y+j*dy[i]]=1;
	  }
	} 
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
	     cin>>ch[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		 search(i,j);//对应的8个方向查找字符串并进行标记 
		}
	}
	for(int i=1;i<=n;i++){
	  for(int j=1;j<=n;j++){
		 if(use[i][j])//满足标记则输出原字符 
		  cout<<ch[i][j];
		 else cout<<"*"; //不满足则输出* 
		}
		cout<<endl;
	}
	return 0;
}

