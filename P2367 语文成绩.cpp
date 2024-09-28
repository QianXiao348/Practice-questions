#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+10; 
int n,p;
int a[N],b[N];
void insert(int l,int r,int c){
	b[l]+=c;
	b[r+1]-=c;
}
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++){
    	 cin>>a[i];
    	 insert(i,i,a[i]);
	}
    
    int ans=INT_MAX;
    while(p--){
    	int l,r,c;
    	cin>>l>>r>>c;
    	insert(l,r,c);
	}
	for(int i=1;i<=n;i++){
	 b[i]+=b[i-1];
	 ans=min(b[i],ans);
    }
    cout<<ans;
	return 0;
}

