#include<bits/stdc++.h>
using namespace std;
int main(){
     string a;
     string b;
     getline(cin,a);//ÿ������ 
     getline(cin,b);
     transform(a.begin(),a.end(),a.begin(),::tolower);//תСд��ĸ 
     transform(b.begin(),b.end(),b.begin(),::tolower);
     a=' '+a+' ';//�ַ�������ǰ��ո���� 
     b=' '+b+' ';
     if(b.find(a)==string::npos)//˵���Ҳ��� 
      cout<<-1<<endl;
    else{
    	int nx=b.find(a);
    	int ny=b.find(a);
    	int sum=0;
    	while(ny!=string::npos){//�ҵ�û��Ϊֹ 
    		sum++;
    		ny=b.find(a,ny+1);//ע����²��ҷ�Χ 
		}
		cout<<sum<<" "<<nx<<endl;
	}
	return 0;
}

