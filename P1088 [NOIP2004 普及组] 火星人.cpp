#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int n,m;
int arr[N];//��¼����
int mars[N];//��¼�����˸��ĳ�ʼ����
bool st[N];//��¼ÿ����ѡûѡ
int res;
bool tp;//�м���������ж��Ƿ��ҵ� 
void dfs(int x)
{   
    if(tp) return;//�ҵ��˾Ͳ�����(��֦)
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
  		arr[x]=0;//���� 
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
