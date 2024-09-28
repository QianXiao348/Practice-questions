#include<bits/stdc++.h>
using namespace std;
//首先构造数组存每个线段间的答案 在从1~len/(n-m)中贪心二分查找答案mid
//当sum<mid满足时就移除石头 累加sum记录移除石头后的当前线段长度 
//并在每次移除的石头后k进行计数 直到sum>=mid或者遍历结束 
//当k<=m时 说明中间值mid取小了 则l=mid+1进行试探
//当k>m时 说明mid取大了 则r=mid-1逼近正确答案
//最后输出r 注意考虑特殊情况当全部移除时 
int len,n,m,before=0;
int a[50010];
int main()
{
    cin>>len>>n>>m;
    for(int i=0;i<n;i++){
    	int now;
		cin>>now;
		a[i]=now-before;
		before=now; 
	}
	a[n]=len-before;
	if(n==m){
		cout<<len;
		return 0;
	}
	int l=1,r=len/(n-m);
    while(l<=r){
    	int k=0,sum,mid=(l+r)/2;
    	for(int i=0;i<=n;i++){//n个石头有n+1个线段 
    		sum=a[i];
    		while(sum<mid&&i<=n){
    			i++;
    			sum+=a[i];
    			k++;
			}
		}
		if(k<=m) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
     return 0;
}
