#include<bits/stdc++.h>
using namespace std;
//���������������Ӧ��������
//�ֱ��������С��ʹ(hi-hj)^2���
//�����˫ָ�� ����ż������������˫ָ����н� 
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
