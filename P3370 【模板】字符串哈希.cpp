#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e4+10, P=131;
string s;
ULL h[N];
//×ÔÈ»Òç³ö¹þÏ£ 
ULL get_hash(string &c){
	ULL ans=0;
	for(int i=0;i<c.size();i++)
		ans=ans*P+(ULL)c[i];
	return ans&0x7fffffff;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		h[i]=get_hash(s);
	}
	sort(h+1,h+1+n);
	int ans=1;
	for(int i=1;i<n;i++){
		if(h[i]!=h[i+1])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
