#include<iostream>
using namespace std;
int main(){
	int n,m,i,j;
	cin>>n>>m;
	int a[n],b[m];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(j=0;j<m;j++){
		cin>>b[j];
		cout<<a[b[j]-1]<<endl;
	}
	return 0;
}
