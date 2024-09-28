#include<bits/stdc++.h>
using namespace std;
int n;
string s; 
int main(){
    cin>>n;
    string len="";
    int id;
    for(int i=0;i<n;i++){
     cin>>s;
     int tlen=s.size();
     int mlen=len.size();
     if(tlen>mlen||tlen==mlen&&s>len){
     	len=s;
     	id=i+1;
	 }
	 }
	 cout<<id<<endl<<len;
	return 0;
}

