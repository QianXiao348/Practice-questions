#include<bits/stdc++.h>
using namespace std;
int arr[20][20];
int dfs(int x,int y){//x������У�y����ջ 
     	if(arr[x][y]) return arr[x][y];
     	//���仯����
     	if(x==0) return 1;//���ȣ������뵽��Ҫ����ȫ��ջ����
     	if(y>0) arr[x][y]+=dfs(x,y-1);
     	arr[x][y]+=dfs(x-1,y+1);
     	return arr[x][y];
}
int main()
{
	int n;
	cin>>n;
	cout<<dfs(n,0);
	return 0;
 } 
