#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int f[N];
int dfs(int n,int x){
	f[1]=1;
	for(int i=2;i<=n;i++){
		if(i%2==0)
		f[i]=f[i-1]+f[i/2];
		else f[i]=f[i-1];
	}
	return f[n];
}
int main()
{
	int n;
	cin>>n;
	cout<<dfs(n,1);
	return 0;
 } 
