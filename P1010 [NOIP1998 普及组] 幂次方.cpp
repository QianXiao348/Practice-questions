#include<bits/stdc++.h>
using namespace std;
int a[20]={1};
void f(int x){
	int flgt=0;
	while(x>=a[flgt]) flgt++;
	flgt--;
	if(flgt==1) cout<<"2";
	else if(flgt==0) cout<<"2(0)";
	else{
		cout<<"2(";
		f(flgt);
		cout<<")";
	}
	x-=a[flgt];
	if(x!=0){
		cout<<"+";
		f(x);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<17;i++)//i´ú±í´ÎÃİ 
	 a[i]=a[i-1]*2;
	f(n);
	return 0;
}
