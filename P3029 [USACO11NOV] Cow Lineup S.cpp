#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+10;
int n,sum,ans=INT_MAX;
map<int,int>m;
struct node{
	int x,id;
}a[N],query[N];
bool cnm(node x,node y){
	return x.x<y.x;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i].x>>a[i].id;
    	m[a[i].id]++;
    	if(m[a[i].id]==1)
    	 sum++;
	}
	sort(a+1,a+n+1,cnm);
	m.clear();
	int l=1,r=0,tot=0;
	for(int i=1;i<=n;i++){
		if(!m[a[i].id])
		m[a[i].id]=1,tot++;
		else
		m[a[i].id]++;
	query[++r]={a[i].x,a[i].id};
	while(m[query[l].id]>1)
	   --m[query[l++].id];
	if(tot==sum)
	  ans=min(ans,query[r].x-query[l].x);
	}
	cout<<ans;
	return 0;
}

