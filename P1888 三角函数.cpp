#include<iostream>
#include<algorithm>
using namespace std;
int gcda(int a,int b)//շת��������Լ�� 
{
	while(int c=a%b)
	{
		a=b;//������������
		b=c;//���������� 
	}
	return b; 
}
int main()
{
	int a[4];
	for(int i=0;i<3;i++)
	 cin>>a[i]; 
	sort(a,a+3);//�����С���� 
	int b=gcda(a[0],a[2]);
	cout<<a[0]/b<<"/"<<a[2]/b<<endl;
	return 0;
}
