#include<iostream>
#include<algorithm>
using namespace std;
int gcda(int a,int b)//辗转相除求最大公约数 
{
	while(int c=a%b)
	{
		a=b;//除数做被除数
		b=c;//余数做除数 
	}
	return b; 
}
int main()
{
	int a[4];
	for(int i=0;i<3;i++)
	 cin>>a[i]; 
	sort(a,a+3);//排序从小到大 
	int b=gcda(a[0],a[2]);
	cout<<a[0]/b<<"/"<<a[2]/b<<endl;
	return 0;
}
