#include<bits/stdc++.h>
using namespace std;
long long w0,w,m; 
int main(){
    scanf("%lld%lld%lld",&w0,&w,&m);
    double l=0,r=10,mid,k;
    while(l<=r){
    	 mid=l+(r-l)/2;
    	if(r-l<0.0001){//��ȷ��0.001 
    		mid=(r+l)/2;
    		break;
		}
    	k=w0;
    	for(int i=0;i<m;i++){
    		k=k*(1+mid)-w;//����������ʹ�ʽ 
		}
		if(k==0){
			printf("%.1f",mid*100);//������ðٷ��� 
			return 0;
		}
		else if(k>0) r=mid;
		else l=mid;
	}
	printf("%.1f",mid*100);
	return 0;
} 
