#include<bits/stdc++.h>
using namespace std;
//��1~�������������ж���Ѱ�Ҵ�mid
//����һ������ֱ��¼ÿ��·�εľ���a[i] 
//���öξ������Ѱ�ҵĴ�mid �����·��count���� ֱ�����о������ 
//��count<kʱ ˵��midȡ���� r=mid-1;
//��count==k Ϊ��ʹ�����С r=mid-1;
//��count>k ˵�����ȡС�� l=mid+1
//����ҵ��������l 
int len,n,k,now,before=0,l=1,r=0;
int a[100010];
int main(){
	scanf("%d%d%d",&len,&n,&k);
	for(int i=0;i<n;i++){
	 scanf("%d",&now);
	 a[i]=now-before;
	 before=now;
	 r=max(r,a[i]);		
	}
	a[n]=len-before;//ע������˾����յ��ǲ��ֵľ���a[n] 
    r=max(r,a[n]); 
    if(k==0){//���� 
      printf("%d",r);
      return 0;
    }
    while(l<=r){
    	int sum,count=0,mid=(l+r)/2;
    	for(int i=0;i<n;i++){
    		sum=a[i];
    		while(sum>mid){
    			count++;
				sum-=mid;
			}
		}
    	if(count<=k) r=mid-1;
    	else l=mid+1;
	}
	 printf("%d",l);
	return 0;
} 
