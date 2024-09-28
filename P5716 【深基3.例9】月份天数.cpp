#include<stdio.h>
int surey(int y){
	if(y%400==0||(y%4==0&&y%100!=0))
	 return 1;
	else 
	 return 0;
}
int main(){
	int month,year;
	scanf("%d%d",&year,&month);
	 int a[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
	 if(surey(year)==1)
	  a[2]=29;
	  else
	  a[2]=28;
	  printf("%d",a[month]);
	return 0;
}
