#include<bits/stdc++.h>
using namespace std;
//���ȹ��������ÿ���߶μ�Ĵ� �ڴ�1~len/(n-m)��̰�Ķ��ֲ��Ҵ�mid
//��sum<mid����ʱ���Ƴ�ʯͷ �ۼ�sum��¼�Ƴ�ʯͷ��ĵ�ǰ�߶γ��� 
//����ÿ���Ƴ���ʯͷ��k���м��� ֱ��sum>=mid���߱������� 
//��k<=mʱ ˵���м�ֵmidȡС�� ��l=mid+1������̽
//��k>mʱ ˵��midȡ���� ��r=mid-1�ƽ���ȷ��
//������r ע�⿼�����������ȫ���Ƴ�ʱ 
int len,n,m,before=0;
int a[50010];
int main()
{
    cin>>len>>n>>m;
    for(int i=0;i<n;i++){
    	int now;
		cin>>now;
		a[i]=now-before;
		before=now; 
	}
	a[n]=len-before;
	if(n==m){
		cout<<len;
		return 0;
	}
	int l=1,r=len/(n-m);
    while(l<=r){
    	int k=0,sum,mid=(l+r)/2;
    	for(int i=0;i<=n;i++){//n��ʯͷ��n+1���߶� 
    		sum=a[i];
    		while(sum<mid&&i<=n){
    			i++;
    			sum+=a[i];
    			k++;
			}
		}
		if(k<=m) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
     return 0;
}
