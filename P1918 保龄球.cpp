#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
unordered_map<int,int>m;
int main(){
    int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		m[x]=i;
	}
	int t;
	cin>>t;
	while(t--){
		int a;
		cin>>a;
		if(m.find(a)!=m.end())
		  cout<<m[a]<<endl;
		else
		  cout<<"0\n"; 
	}
	return 0;
}

