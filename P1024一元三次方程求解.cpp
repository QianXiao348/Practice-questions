#include<bits/stdc++.h>
using namespace std;
//������-100~100���ҵ�f(i)==0�����i ֮����ȥi��i+1ֱ��ȥ������f(i)*(i+1)<0���� 
//������������������i��i+1�� ������r-l�����С��0.001��ֱ�����r 
//������f(mid)==0ֱ�����mid  ������f(l)*f(mid)<0��r=mid���µ��øú������ж��ֲ��� 
//������f(l)*f(mid)>0��l=mid���µ��øú������ж��ֲ��� 
double a,b,c,d,l,r,mid;
double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
void find(double l,double r){
	if(r-l<0.001){
		printf("%.2f ",r);
		return;
	}
	mid=(l+r)/2;
	if(f(mid)==0){
		printf("%.2f ",mid);
		return;
	}
	if(f(mid)*f(l)<0) 
	 find(l,mid);
	else find(mid,r);
	
}
int main()
{
	int mark=0;
	cin>>a>>b>>c>>d;
	for(double i=-100;i<=100&&mark!=3;i++){
		double  j=i+1;
		if(f(i)==0){
			printf("%.2f ",i);
			mark++;
			continue;
		}
		 if(f(j)*f(i)<0){
		  find(i,j);
		  mark++;
		 }
	}
	return 0;
}
