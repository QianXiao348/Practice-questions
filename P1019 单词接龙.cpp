#include<bits/stdc++.h>
using namespace std;
const int N=25; 
int n;
string s[25];
int use[N];//记录每个单词的使用次数
int g[N][N];//记录i后面接j单词 最小重合数 
int ans=0;//记录最大长度 
void dfs(string danci,int x){
	ans=max(ans,(int)danci.size());//都转为int类型 
	use[x]++;
	for(int i=0;i<n;i++){ 
	   if(g[x][i]&&use[i]<2){//找到满足条件的继续找下去
	   	dfs(danci+s[i].substr(g[x][i]),i);
	   }	
	}
	use[x]--;//不满足则进行回溯 
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
				 if(a.substr(a.size()-k,k)==b.substr(0,k)){//从末尾开始往前比较字符串重合 
				 	g[i][j]=k;//记录重合字符数 
				 	break;
				 }
			}
		}
	}
	for(int i=0;i<n;i++){
			if(s[i][0]==start){
				dfs(s[i],i);//i代表开始位置
			}
	}
	 cout<<ans<<endl;
	return 0;
}

