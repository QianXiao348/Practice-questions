#include<iostream>
using namespace std;
int dichotomy_1(int a[],int x,int l,int r)
{
	while(l<r){
		int mid=l+r>>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	if(a[l]==x) return l;
	else return -1;
}
int main()
{
	int n,m,i,x;
	scanf("%d%d",&n,&m);
	int a[n];
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	while(m--){
		scanf("%d",&x);
		cout<<dichotomy_1(a,x,1,n)<<" ";
	}
	return 0;
}
