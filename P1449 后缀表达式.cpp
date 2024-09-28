#include<iostream>
#include<stack>
#include<string>
using namespace std;
string c;
stack<int>s;
int main(){
	cin>>c;
	int a,b,k,x=0,y=0;
	for(k=0;k<c.length();k++){
		if(c[k]=='@') break;
		else if(c[k]>='0'&&c[k]<='9'){
			y=x*10+c[k]-'0';
			x=y;
		}
		else if(c[k]=='.'){
			s.push(x);
			x=0,y=0;//压栈后重置每次循环得到的数 
		}
		else{
			 if(c[k]=='-') b=s.top(),s.pop(),a=s.top(),s.pop(),s.push(a-b);
			 if(c[k]=='+') b=s.top(),s.pop(),a=s.top(),s.pop(),s.push(a+b);
		     if(c[k]=='*') b=s.top(),s.pop(),a=s.top(),s.pop(),s.push(a*b);
			 if(c[k]=='/') b=s.top(),s.pop(),a=s.top(),s.pop(),s.push(a/b);
		}
	}
	cout<<s.top()<<endl;
	return 0;
}
