#include<bits/stdc++.h>
using namespace std;
const int N=202;
int nums[N];
int n,a,b,ans=INT_MAX;
bool use[N];//记录没有走过的 
void dfs(int x,int cnt){
	if(cnt>ans)
	 return;
	if(x==b){
	   ans=min(ans,cnt);
	   return;
	}
	if(x+nums[x]<=n&&!use[x+nums[x]]){//往上走 
	   use[x+nums[x]]=true;
	   dfs(x+nums[x],cnt+1);
	   use[x+nums[x]]=false;
	}
	if(x-nums[x]>0&&!use[x-nums[x]]){//往下走 
	   use[x-nums[x]]=true;
	  dfs(x-nums[x],cnt+1);
	  use[x-nums[x]]=false;
	} 
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
     scanf("%d",&nums[i]);
    dfs(a,0);
    if(ans==INT_MAX){
    	printf("-1");
    	return 0;
	}
	printf("%d",ans);
	return 0;
}

