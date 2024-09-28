#include<bits/stdc++.h>
using namespace std;
//一开始将所有大于x的数变为x大小,并且记录减少的个数
//在遍历依次判断两数是否满足条件
//如果不满足就减掉刚好满足条件的数并记录 
int main()
{
    long long n,x,ans=0;
	long long a[100010];
	scanf("%lld%lld",&n,&x);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>x){ 
			long long t=0;
			t=a[i]-x;
			a[i]=x;
			ans+=t;
		}
	}
	for(int i=1;i<n;i++){
		long long t1=a[i]+a[i-1];
		if(t1>x){
			t1-=x;
			ans+=t1;
			a[i]-=t1;
		}
	}
	printf("%lld",ans);
	return 0;
 } 
