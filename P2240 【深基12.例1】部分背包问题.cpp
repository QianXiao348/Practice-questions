#include<bits/stdc++.h>
using namespace std;
struct coin{
	int m,v;
	double aver;
}a[110];
bool cnm(coin b,coin c)
{
	return b.aver>c.aver;
}
int main()
{
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++){
	cin>>a[i].m>>a[i].v;
	a[i].aver=1.0*a[i].v/a[i].m;
	}
	sort(a,a+n,cnm);
	int k=0;
	double ans=0;
	while(t>0&&k<n){//k<n是因为万一背包空间特别大，东西装完了，还会继续循环装 
		if(t>=a[k].m){
			ans+=a[k].v;
			t-=a[k].m;
			k++;
		}
		else{
			ans+=a[k].aver*t;
			t-=t;
			k++;
		}
	}
	printf("%.2f",ans);
	return 0;
 } 
