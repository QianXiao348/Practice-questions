#include<bits/stdc++.h>
using namespace std;
int n;
int a[10];
void dfs(int sum,int step,int index){
	//sum为累加和 step当前遍历到深度 index每次开始的位置 
	if(sum==n){
		for(int i=1;i<step-1;i++)
		 cout<<a[i]<<"+";
		cout<<a[step-1]<<endl;
		return ;
	}
	if(sum>n) return;
	for(int i=1;i<n;i++){
		a[step]=i;
		dfs(sum+i,step+1,i);
		a[step]=0;//回溯 
	} 
}
int main(){
    cin>>n;
 	dfs(0,1,1);
	return 0;
}

