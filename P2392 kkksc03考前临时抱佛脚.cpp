#include<bits/stdc++.h>
using namespace std;
int s[5],a[5][22],ans=0,mark[5]={0,1200,1200,1200,1200};
void dfs(int l,int r,int step,int row){
	if(step==s[row]){
		int temp=max(l,r);
		if(temp<mark[row])
		 mark[row]=temp;
		 return;
	}
	step++;
	dfs(a[row][step]+l,r,step,row);
	dfs(l,a[row][step]+r,step,row);
}
int main(){
    for(int i=1;i<5;i++) 
	  cin>>s[i];
    for(int i=1;i<5;i++)
     for(int j=1;j<=s[i];j++)
    	 cin>>a[i][j];
    for(int i=1;i<=4;i++){
    	dfs(0,0,0,i);
    	ans+=mark[i];
	}
    cout<<ans;
	return 0;
}

