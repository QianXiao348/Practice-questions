#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
struct milk{
	int price,nums; 
}a[5010];
bool cnm(milk zc,milk zx){
	return zc.price<zx.price;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
     scanf("%d%d",&a[i].price,&a[i].nums);
    sort(a+1,a+m+1,cnm);
    for(int i=1;i<=m;i++){
    	if(n>=a[i].nums){
    		ans+=a[i].nums*a[i].price;
    		n-=a[i].nums;
		}
		else{
			ans+=n*a[i].price;
			n=0;
			break;
		}	
	}
	printf("%d",ans);
	return 0;
 } 
