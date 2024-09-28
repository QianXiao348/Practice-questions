#include<bits/stdc++.h>
using namespace std;
//从1~数组中最大的数中二分寻找答案mid
//构造一个数组分别记录每个路段的距离a[i] 
//当该段距离大于寻找的答案mid 则插入路标count计数 直到所有距离查完 
//当count<k时 说明mid取大了 r=mid-1;
//当count==k 为了使结果跟小 r=mid-1;
//当count>k 说明结果取小了 l=mid+1
//最后找到后输出答案l 
int len,n,k,now,before=0,l=1,r=0;
int a[100010];
int main(){
	scanf("%d%d%d",&len,&n,&k);
	for(int i=0;i<n;i++){
	 scanf("%d",&now);
	 a[i]=now-before;
	 before=now;
	 r=max(r,a[i]);		
	}
	a[n]=len-before;//注意别忘了距离终点那部分的距离a[n] 
    r=max(r,a[n]); 
    if(k==0){//特判 
      printf("%d",r);
      return 0;
    }
    while(l<=r){
    	int sum,count=0,mid=(l+r)/2;
    	for(int i=0;i<n;i++){
    		sum=a[i];
    		while(sum>mid){
    			count++;
				sum-=mid;
			}
		}
    	if(count<=k) r=mid-1;
    	else l=mid+1;
	}
	 printf("%d",l);
	return 0;
} 
