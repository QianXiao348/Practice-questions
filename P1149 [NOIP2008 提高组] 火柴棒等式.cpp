#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int n;
int arr[N];
int q[N]={6,2,5,5,4,5,6,3,7,6};//ÿ�����ִ�������� 
int ans;
void dfs(int x,int sum)//ö����������A+B=C���� 
{//��ǰxö��λ�ã�sum���û���� 
     if(sum>n) return;//��֦ 
	if(x>3){
		if(arr[1]+arr[2]==arr[3]&&sum==n)
		  ans++;
		return;
	}
	for(int i=0;i<=1000;i++){
		arr[x]=i;
		dfs(x+1,sum+q[i]);
		arr[x]=0;//�ָ� 
	} 
}
int main()
{
	scanf("%d",&n);
	//����ÿ�����Ļ���� 
	for(int i=10;i<=1000;i++)
	  q[i]=q[i/10]+q[i%10];
	dfs(1,4); 
	printf("%d",ans);
	return 0;
 } 
