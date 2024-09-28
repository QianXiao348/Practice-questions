#include<bits/stdc++.h>
using namespace std;
//首先在-100~100间找到f(i)==0则输出i 之后再去i和i+1直接去找满足f(i)*(i+1)<0的数 
//在满足上述条件后在i和i+1中 若满足r-l的误差小于0.001则直接输出r 
//若满足f(mid)==0直接输出mid  若满足f(l)*f(mid)<0则r=mid重新调用该函数进行二分查找 
//若满足f(l)*f(mid)>0则l=mid重新调用该函数进行二分查找 
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
