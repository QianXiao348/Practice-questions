#include<bits/stdc++.h>
using namespace std;
string s;
int n,mark=0,k,flag=0;
//ע��Ҫ�����λ�ò��ܱ� ��ȥ��ǰ��0 
//ÿ����k+1��ȡһ����С���� Ȼ��mark��λȡ��λ��+1
int fetch(int l,int r)
{
	char min1=s[l];
	mark+=1;
	for(int i=mark;i<=r;i++){
		if(s[i]<min1){
			min1=s[i];
			mark=i+1;
		}
	}
	return min1-'0';
}
int main()
{
	cin>>s>>k;
	n=s.length();
	for(int i=0;i<n-k;i++){
	  int temp=fetch(mark,k+i);
		if(temp==0&&flag==0) continue;//ȥ��ǰ��0 
		flag=1;
		cout<<temp;
	}
	if(flag==0)
	 cout<<0; 
	return 0;
 } 
