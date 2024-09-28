#include<bits/stdc++.h>
using namespace std;
string dfs()
{
	string s="",str="";
	char c;
	int n;
	while(cin>>c){
		if(c=='['){
			cin>>n;
			str=dfs();
		while(n--)
			 s+=str;
		}
		else if(c==']'){
		  return s;
		}
		else
		  s+=c;
	}
}
int main()
{
    cout<<dfs();
	return 0;
 } 
