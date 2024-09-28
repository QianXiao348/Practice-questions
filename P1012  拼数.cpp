#include<bits/stdc++.h>
using namespace std;
int n; 
string s[25];
bool cnm(const string &a,const string &b)
{
	return a+b>b+a;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
     cin>>s[i];
     sort(s,s+n,cnm);
     for(int i=0;i<n;i++)
      cout<<s[i];
	return 0;
}

