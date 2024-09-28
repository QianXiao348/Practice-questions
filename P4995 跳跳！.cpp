#include<bits/stdc++.h>
using namespace std;
//若是体力消耗最大应该先排序
//分别往最大最小跳使(hi-hj)^2最大
//则采用双指针 用奇偶次数来看控制双指针的行进 
int n;
long long sum=0;
int a[310];
bool cnm(int zx,int zc){
	return zx>zc;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	sort(a,a+n,cnm);
	sum+=pow(a[0],2);
	int r=n-1,l=0,k=0;
	while(l<=r){
		sum+=pow(abs(a[l]-a[r]),2);
		k++;
		if(k%2==1)
		l++;
		else
		r--;
	}
	cout<<sum;
	return 0;
}
