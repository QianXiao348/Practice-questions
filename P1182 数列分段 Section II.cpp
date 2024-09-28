#include<bits/stdc++.h>
using namespace std;
//在题目数组的最大值~数组和中进行二分查找答案mid
//记录数组中本身和累加和为sum 当sum+a[i]<=mid继续累加
//直到sum+a[i]>mid 记录划分的段为k 注意本身线段k为1 
//当k<=m时说明mid取大了 则r=mid-1进行试探;
//当k>m时mid取小了 则l=mid+1逼近正确答案 
//最后输出l 
int n,m;
int a[100010];
int main()
{
	int l=0,r=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	    l=max(l,a[i]);
	    r+=a[i];
	}
	while(l<=r){
	   int k=1,sum=0,mid=(l+r)/2;
	   for(int i=0;i<n;i++){
	    if(a[i]+sum<=mid)
	     sum+=a[i];
	     else{
	     	sum=a[i];
	     	k++;
		 }
	   }
	   if(k<=m) r=mid-1;
	   else  l=mid+1;
	}
	printf("%d",l);	 
	return 0;
}
