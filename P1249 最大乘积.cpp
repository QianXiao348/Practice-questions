#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1e5+10;
vector<int> mul(vector<int> &A,int &b){
	vector<int>C;
	int t=0;
	for(int i=0;i<A.size();i++){
		t+=A[i]*b;
		C.push_back(t%10);
		t/=10;
	}
	while(t){
		C.push_back(t%10);
		t/=10;
	}
	while(C.size()>1&&C.back()==0) C.pop_back();
	return C;
}
void solve(){
	int n;
	cin>>n;
	int sum=0,t=2;
	vector<int>a;
	while(sum<=n){
		sum+=t;
		a.push_back(t);
		t++;
	}
	if(sum-n==1){
		a.front()=1;
		++a.back();
	}
	else{
		auto it=find(a.begin(),a.end(),sum-n);
		if(it!=a.end()) *it=1;
	}
	vector<int>ans(1,1);
	for(int i=0;i<a.size();i++){
		if(a[i]==1) continue;
		cout<<a[i]<<" ";
		ans=mul(ans,a[i]);
	}
	cout<<endl;
	for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];
	cout<<endl;
}
int main(){
	PASE;
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}


