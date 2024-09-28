#include<bits/stdc++.h>
using namespace std;
const int  N=11;
int ans,n;
int arr[N],a[590050][N];
void dfs(int x,int sum)
{//sum表示已选的调料总质量,x代表枚举到了哪里 
	if(sum>n) return;//剪枝 
	if(x>10){
		if(sum==n){
			ans++;
		for(int i=1;i<=10;i++){	
		  a[ans][i]=arr[i];	
		   } 
		}
		return;
	} 
	for(int i=1;i<=3;i++){
		arr[x]=i;
		dfs(x+1,sum+i);
		arr[x]=0;
	}
}  
int main()
{
	scanf("%d",&n);
	dfs(1,0);
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++){
			 for(int j=1;j<=10;j++)
	  printf("%d ",a[i][j]);
	printf("\n");
	}
	return 0;
 } 
