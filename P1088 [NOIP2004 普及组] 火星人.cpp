#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int n,m;
int arr[N];//记录方案
int mars[N];//记录火星人给的初始方案
bool st[N];//记录每个数选没选
int res;
bool tp;//中间变量用于判断是否找到 
void dfs(int x)
{   
    if(tp) return;//找到了就不找了(剪枝)
	if(x>n){
		res++;
		if(res==m+1){
			for(int i=1;i<=n;i++)
			 printf("%d ",arr[i]);
		   tp=true;
		}
		return;
	}
  for(int i=1;i<=n;i++){
  	if(!res){
  		i=mars[x];
	  }
  	if(!st[i]){
  		arr[x]=i;
  		st[i]=true;
  		dfs(x+1);
  		arr[x]=0;//回溯 
  		st[i]=false;
	  }
  }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
     scanf("%d",&mars[i]);
     dfs(1);
    return 0;
}
