#include<bits/stdc++.h>
using namespace std;
int n,ans=0,mark=0;
int a[100010];
//f[i]��ʾ��i������Ҫ��Ĵ����Ƕ��� 
//ͨ�����Ʒ��ֵ�a[i-1]>=a[i]ʱf[i]=f[i-1]; 
//��a[i-1]<a[i]ʱf[i]=f[i-1]+(a[i-1]-a[i]); 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
     scanf("%d",&a[i]);
     vector<int>f(n+1);
    f[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i-1]>=a[i])
		 f[i]=f[i-1];
		else f[i]=f[i-1]+(a[i]-a[i-1]);
	}
	printf("%d",f[n]); 
	return 0;
 } 
