#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int mod = 1e9+7;
const int N = 1e6+10;
int s1,s2,s3,s4; //±íÊ¾4¸ö×´Ì¬ 
int main(){
	PASE;
	int n;
    cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==1){
			s1=s1+1;
			s3=max(s2+1,s3+1);
		}
		else{
			s2=max(s1+1,s2+1);
			s4=max(s3+1,s4+1);
		}
	}
	cout<<max({s1,s2,s3,s4})<<endl;
	
	return 0;
}

