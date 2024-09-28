#include<bits/stdc++.h>
using namespace std;
//首先排序录取分数从小到达 
//利用二分法找到一个刚好大于预期又小于预期的位置进行插入运算
//把开头 结尾特殊的进行判断了 
//然后将找到的位置前后差比较取最小的为答案
int m,n;
long long ans=0;
int admission[1000010],estimate[1000010];
int find(int x){
		int mid,l=0,r=m-1;
	while(true){
		 mid=(r+l)/2;
		 if(admission[mid]==x) return 0;
		 else if(admission[mid]<=x&&admission[mid+1]>=x)
		    return min(x-admission[mid],admission[mid+1]-x);
		 else if(admission[mid]<x)
		            l=mid+1;
		else r=mid;
	  }
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++) 
	 scanf("%d",&admission[i]);
	for(int j=0;j<n;j++) 
	 scanf("%d",&estimate[j]);
	sort(admission,admission+m);
	for(int i=0;i<n;i++){
		if(admission[0]>=estimate[i]) 
		  ans+=admission[0]-estimate[i];
		else if(admission[m-1]<=estimate[i])
		   ans+=estimate[i]-admission[m-1];
		else ans+=find(estimate[i]);
	}
	printf("%lld",ans);
	return 0;
}
