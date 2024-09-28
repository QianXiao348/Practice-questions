#include<bits/stdc++.h>
using namespace std;
int main(){
     string a;
     string b;
     getline(cin,a);//每行输入 
     getline(cin,b);
     transform(a.begin(),a.end(),a.begin(),::tolower);//转小写字母 
     transform(b.begin(),b.end(),b.begin(),::tolower);
     a=' '+a+' ';//字符串进行前后空格添加 
     b=' '+b+' ';
     if(b.find(a)==string::npos)//说明找不到 
      cout<<-1<<endl;
    else{
    	int nx=b.find(a);
    	int ny=b.find(a);
    	int sum=0;
    	while(ny!=string::npos){//找到没有为止 
    		sum++;
    		ny=b.find(a,ny+1);//注意更新查找范围 
		}
		cout<<sum<<" "<<nx<<endl;
	}
	return 0;
}

