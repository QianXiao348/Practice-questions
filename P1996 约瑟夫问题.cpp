#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n,m,i,count=0;
	queue<int>q;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	 q.push(i);
	while(!q.empty()){
		for(i=1;i<m;i++)
		{
			q.push(q.front());//将队首放在队尾
			 q.pop();
		}
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
 } 
