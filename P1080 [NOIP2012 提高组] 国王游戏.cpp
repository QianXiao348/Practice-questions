#include<bits/stdc++.h>
using namespace std;
//�ƶϳ�����*���ֵ�ֵ������ǵõ������ȴ���ٽ�� 
//Ȼ��߾��� 
int n;
int b[10010]={1},ans[10010],slen=1;
struct dacheng{
	int x,y;
}a[10010];
bool cnm(dacheng zx,dacheng zc){
	return zx.x*zx.y<zc.x*zc.y;
}
void gaocheng(int k){
	int temp=0;
   for(int i=0;i<slen;i++)
    b[i]*=k;
   for(int i=0;i<slen;i++){//��λ 
   	temp=temp+b[i];
   	b[i]=temp%10;
   	temp/=10;
   }
    while(temp!=0){
    	b[slen]=temp%10;
    	slen++;
    	temp/=10;
	}
	return;
}
void gaochu(int k){
	int temp=0;
	for(int i=slen-1;i>=0;i--){
		temp=temp*10+b[i];
		ans[i]=temp/k;
		temp%=k;
	}
	return ;
}
void print(){
	int temp=slen;
	while(ans[temp]==0){
		temp--;
		if(temp==-1){
			cout<<1;
			return;
		}
	}
	for(int i=temp;i>=0;i--)
	 cout<<ans[i];
	 return;
}
int main(){
     cin>>n;
     for(int i=0;i<=n;i++){
     	cin>>a[i].x>>a[i].y;
	 }
      sort(a+1,a+n+1,cnm);//�������������� 
      for(int i=0;i<n;i++){
      	gaocheng(a[i].x);//�߾��ȳ˵;��� 
	  }
	  gaochu(a[n].y);//�߾��ȳ��;��� 
	  print();//����߾��� 
	return 0;
}
