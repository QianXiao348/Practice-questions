#include<bits/stdc++.h> //lis:dp 
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 1010;
vector<int>a;
int f[N];
int g[N],gl;
int main(){
	PASE;
	int x;
	while(cin>>x){
		a.push_back(x);
	}
	int res=0;
	for(int i=0;i<a.size();i++){
		f[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]>a[i])
				f[i]=max(f[i],f[j]+1);
		}
		res=max(res,f[i]);
	}
	int cnt=0;
	for(int i=0;i<a.size();i++){
		int k=0;
		while(k<cnt&&g[k]<a[i]) k++;
		g[k]=a[i];
//		cout<<"k: "<<k<<endl;
//		cout<<"cnt: "<<cnt<<endl;
		if(k>=cnt) cnt++;
	}
	cout<<res<<endl<<cnt<<endl;
	return 0;
}

