#include<bits/stdc++.h>
using namespace std;
int arr[20][20];
int dfs(int x,int y){//x代表队列，y代表栈 
     	if(arr[x][y]) return arr[x][y];
     	//记忆化搜索
     	if(x==0) return 1;//首先，可以想到，要是数全在栈里了
     	if(y>0) arr[x][y]+=dfs(x,y-1);
     	arr[x][y]+=dfs(x-1,y+1);
     	return arr[x][y];
}
int main()
{
	int n;
	cin>>n;
	cout<<dfs(n,0);
	return 0;
 } 
