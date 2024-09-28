#include<bits/stdc++.h>
using namespace std;
int n,ans=1e9;
const int N = 20;
int sweet[N],bitter[N];
int st[N];
void dfs(int x)
{ 
	if(x>n){
		bool bolway=false; //记录是否有方案选 
		int sum1=1,sum2=0;
     for(int i=1;i<=n;i++){
     	if(st[i]==1){
     		bolway=true;//标记有方案选 
     		sum1*=sweet[i];
     		sum2+=bitter[i];
		 } 
	   }
	   if(bolway)//方案的答案比较 
	   ans=min(ans,abs(sum2-sum1));
	   return ;
	}
	   st[x]=1;//选 
	   dfs(x+1);
	   st[x]=0;
	   //不选 
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
