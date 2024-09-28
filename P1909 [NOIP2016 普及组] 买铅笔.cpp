#include<stdio.h>
typedef struct pen{
     int number,price,sum;
}sq;
int main(){
	int n,i;
	sq a[3];
	scanf("%d",&n);
	for(i=0;i<3;i++){ 
		scanf("%d%d",&a[i].number,&a[i].price);
		if(n%a[i].number!=0)//分别计算价格 
		 a[i].sum=(n/a[i].number+1)*a[i].price;
		else
		 a[i].sum=(n/a[i].number)*a[i].price;
	}
	int min=a[0].sum,t;//比较大小 
	for(i=0;i<3;i++)
	 if(a[i].sum<min){
	  min=a[i].sum;
	 }
	 printf("%d",min);
	return 0;
} 
