#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+10;
int n,m,a[N],c[N],l[N],r[N];
ll b[N];
bool check(int x){
	memset(b,0,sizeof b);
	for(int i=1;i<=x;i++){
		b[l[i]]+=c[i];
		b[r[i]+1]-=c[i];
	}
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		if(b[i]>a[i])
			return 0;
	}
	return 1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
       cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>c[i]>>l[i]>>r[i];
	int l=1,r=m;
	if(check(m)){
		cout<<"0";
		return 0;
	}
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<"-1"<<"\n"<<l;
	return 0;
}

