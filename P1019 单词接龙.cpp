#include<bits/stdc++.h>
using namespace std;
const int N=25; 
int n;
string s[25];
int use[N];//��¼ÿ�����ʵ�ʹ�ô���
int g[N][N];//��¼i�����j���� ��С�غ��� 
int ans=0;//��¼��󳤶� 
void dfs(string danci,int x){
	ans=max(ans,(int)danci.size());//��תΪint���� 
	use[x]++;
	for(int i=0;i<n;i++){ 
	   if(g[x][i]&&use[i]<2){//�ҵ����������ļ�������ȥ
	   	dfs(danci+s[i].substr(g[x][i]),i);
	   }	
	}
	use[x]--;//����������л��� 
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>s[i];
	}
	char start;
	cin>>start;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			string a=s[i],b=s[j];
			for(int k=1;k<min(a.size(),b.size());k++){
				 if(a.substr(a.size()-k,k)==b.substr(0,k)){//��ĩβ��ʼ��ǰ�Ƚ��ַ����غ� 
				 	g[i][j]=k;//��¼�غ��ַ��� 
				 	break;
				 }
			}
		}
	}
	for(int i=0;i<n;i++){
			if(s[i][0]==start){
				dfs(s[i],i);//i����ʼλ��
			}
	}
	 cout<<ans<<endl;
	return 0;
}

