#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//�ӷ�Χ0~1e9��ʼ���ֲ���mid
//sumΪ�ۼӿ�����ľ�ĳ��� sum+=hight[i]-mid 
//��sum>m˵�������� mid��ƫС��l=mid+1; 
//��sum<m��mid��ƫ���� ��r=mid-1;
//��sum==m��������mid��������궼û�ҵ���������r��ƽ��� 
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
