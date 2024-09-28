#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
void dfs(int sum,int cnt,int startindex){
//sum记录累计和 记录取数的次数 代表开始的位置
	if(cnt==k){
	    if(sum==n)//判断并剪枝 
		ans++;
		return;
	}
	for(int i=startindex;i<=n&&sum+i<=n;i++){//sum+i<=n为剪枝
		sum+=i;
		dfs(sum,cnt+1,i);
		sum-=i;//回溯
	}
}
int main(){
    cin>>n>>k;
    dfs(0,0,1);
    cout<<ans<<endl;
	return 0;
}
