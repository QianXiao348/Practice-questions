#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//从范围0~1e9开始二分查找mid
//sum为累加砍掉树木的长度 sum+=hight[i]-mid 
//当sum>m说明砍多了 mid答案偏小则l=mid+1; 
//当sum<m则mid答案偏多了 则r=mid-1;
//若sum==m则最佳输出mid，如果找完都没找到最佳则输出r最逼近答案 
ll n,m;
ll hight[1000010];
bool cnm(ll qw,ll qe){
	return qw>qe;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	 scanf("%lld",&hight[i]);
	sort(hight+1,hight+n+1,cnm);
	ll l=0,r=1000000000;
	while(l<=r){
		ll mid=l+(r-l)/2;
	     ll sum=0;
		for(int j=1;j<=n;j++){
		  if(mid<hight[j])
			sum+=hight[j]-mid;
		else break;
	    }
	    if(sum>m)
	     l=mid+1;
	    else if(sum<m)
	     r=mid-1;
	    else{
	     printf("%lld",mid);
			return 0;
		}
    }
    printf("%lld",r);
    return 0; 
 } 
