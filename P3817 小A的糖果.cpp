#include<bits/stdc++.h>
using namespace std;
//һ��ʼ�����д���x������Ϊx��С,���Ҽ�¼���ٵĸ���
//�ڱ��������ж������Ƿ���������
//���������ͼ����պ�����������������¼ 
int main()
{
    long long n,x,ans=0;
	long long a[100010];
	scanf("%lld%lld",&n,&x);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>x){ 
			long long t=0;
			t=a[i]-x;
			a[i]=x;
			ans+=t;
		}
	}
	for(int i=1;i<n;i++){
		long long t1=a[i]+a[i-1];
		if(t1>x){
			t1-=x;
			ans+=t1;
			a[i]-=t1;
		}
	}
	printf("%lld",ans);
	return 0;
 } 
