#include<bits/stdc++.h>
using namespace std;
//ÿ���˽�ˮ�ᵼ�º��������˵ȴ� ����ˮ������˾Ͳ���Ҫ�ȴ�
//������� ����ʱ��i���˵�ǰ��ˮ���ᵼ��n-i���˵ȴ�  ���еȴ�ʱ���/n���� 
struct que{
	int t,k;
}a[1010];
bool cnm(que b,que c)
{
	return b.t<c.t;
}
int main()
{
	int n,t;
	double ans,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t;
		a[i].k=i;
	}
	sort(a+1,a+n+1,cnm);
	for(int i=1;i<=n;i++){
	    printf("%d ",a[i].k);
	     sum+=(n-i)*a[i].t;
	}
	printf("\n");
	ans=sum/n;
	printf("%.2f",ans);
 } 
