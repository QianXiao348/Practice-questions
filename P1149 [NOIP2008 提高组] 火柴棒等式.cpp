#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int n;
int arr[N];
int q[N]={6,2,5,5,4,5,6,3,7,6};//每个数字代表火柴棍数 
int ans;
void dfs(int x,int sum)//枚举所有满足A+B=C的数 
{//当前x枚举位置，sum所用火柴数 
     if(sum>n) return;//剪枝 
	if(x>3){
		if(arr[1]+arr[2]==arr[3]&&sum==n)
		  ans++;
		return;
	}
	for(int i=0;i<=1000;i++){
		arr[x]=i;
		dfs(x+1,sum+q[i]);
		arr[x]=0;//恢复 
	} 
}
int main()
{
	scanf("%d",&n);
	//递推每个数的火柴数 
	for(int i=10;i<=1000;i++)
	  q[i]=q[i/10]+q[i%10];
	dfs(1,4); 
	printf("%d",ans);
	return 0;
 } 
