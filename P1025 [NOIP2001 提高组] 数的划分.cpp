#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
void dfs(int sum,int cnt,int startindex){
//sum��¼�ۼƺ� ��¼ȡ���Ĵ��� ����ʼ��λ��
	if(cnt==k){
	    if(sum==n)//�жϲ���֦ 
		ans++;
		return;
	}
	for(int i=startindex;i<=n&&sum+i<=n;i++){//sum+i<=nΪ��֦
		sum+=i;
		dfs(sum,cnt+1,i);
		sum-=i;//����
	}
}
int main(){
    cin>>n>>k;
    dfs(0,0,1);
    cout<<ans<<endl;
	return 0;
}
