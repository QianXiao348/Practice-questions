#include<bits/stdc++.h>
using namespace std;
int n,ans=1e9;
const int N = 20;
int sweet[N],bitter[N];
int st[N];
void dfs(int x)
{ 
	if(x>n){
		bool bolway=false; //��¼�Ƿ��з���ѡ 
		int sum1=1,sum2=0;
     for(int i=1;i<=n;i++){
     	if(st[i]==1){
     		bolway=true;//����з���ѡ 
     		sum1*=sweet[i];
     		sum2+=bitter[i];
		 } 
	   }
	   if(bolway)//�����Ĵ𰸱Ƚ� 
	   ans=min(ans,abs(sum2-sum1));
	   return ;
	}
	   st[x]=1;//ѡ 
	   dfs(x+1);
	   st[x]=0;
	   //��ѡ 
	   st[x]=2;
	   dfs(x+1);
	   st[x]=0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&sweet[i],&bitter[i]);
		}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
