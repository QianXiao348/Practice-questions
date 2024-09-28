#include<stdio.h>
int main(){
	int a[3],t,i,j;
	for(i=0;i<3;i++)
	scanf("%d",&a[i]);
	for(i=1;i<3;i++)//ÅÅ´óÐ¡ 
	 for(j=0;j<3-i;j++)
	  if(a[j]>a[j+1]){
	 	t=a[j];
	 	a[j]=a[j+1];
	 	a[j+1]=t;
	   }
	if(a[0]+a[1]<=a[2]){
	 printf("Not triangle");
	 return 0;
	}
	if(a[0]*a[0]+a[1]*a[1]>a[2]*a[2])
	  printf("Acute triangle\n");
	else if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
	  printf("Right triangle\n");
	else if(a[0]*a[0]+a[1]*a[1]<a[2]*a[2])
	  printf("Obtuse triangle\n");
	if(a[0]==a[1]||a[1]==a[2])
	 printf("Isosceles triangle\n");
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[0])
	 printf("Equilateral triangle\n");
	return 0;
}
