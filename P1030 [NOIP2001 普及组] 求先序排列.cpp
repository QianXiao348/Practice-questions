#include<bits/stdc++.h>
using namespace std;
void dfs(string z,string h){
	if(z.size()>0){
		char ch=h[h.size()-1];
		cout<<ch;
		int k=z.find(ch);
		dfs(z.substr(0,k),h.substr(0,k));//×ó×ÓÊ÷
		dfs(z.substr(k+1),h.substr(k,h.size()-1-k));//ÓÒ×ÓÊ÷ 
	}
}
int main(){
    string z,h;
    cin>>z>>h;
    dfs(z,h);
	return 0;
}

