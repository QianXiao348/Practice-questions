#include<iostream>
#include<string>
using namespace std;
const int max1=1e6+5;
struct {
	string name;
	int head;
}a[max1];
int main(){
	int n,m,i,j,x,y;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i].head>>a[i].name;
	}
	int now=0;
	for(i=1;i<=m;i++){
		cin>>x>>y;
		if(a[now].head==0&&x==0)//分别讨论每种情况 
		 now=(now+n-y)%n;
		else if(a[now].head==0&&x==1)
		 now=(now+y)%n;
		else if(a[now].head==1&&x==0)
		 now=(now+y)%n;
		else if(a[now].head==1&&x==1)
		 now=(now+n-y)%n;
	}
	cout<<a[now].name<<endl; 
	return 0;
}
