#include<bits/stdc++.h>
using namespace std;
//����Ŀ��������ֵ~������н��ж��ֲ��Ҵ�mid
//��¼�����б�����ۼӺ�Ϊsum ��sum+a[i]<=mid�����ۼ�
//ֱ��sum+a[i]>mid ��¼���ֵĶ�Ϊk ע�Ȿ���߶�kΪ1 
//��k<=mʱ˵��midȡ���� ��r=mid-1������̽;
//��k>mʱmidȡС�� ��l=mid+1�ƽ���ȷ�� 
//������l 
int n,m;
int a[100010];
int main()
{
	int l=0,r=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	    l=max(l,a[i]);
	    r+=a[i];
	}
	while(l<=r){
	   int k=1,sum=0,mid=(l+r)/2;
	   for(int i=0;i<n;i++){
	    if(a[i]+sum<=mid)
	     sum+=a[i];
	     else{
	     	sum=a[i];
	     	k++;
		 }
	   }
	   if(k<=m) r=mid-1;
	   else  l=mid+1;
	}
	printf("%d",l);	 
	return 0;
}
