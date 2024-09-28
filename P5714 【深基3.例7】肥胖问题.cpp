#include<stdio.h>
int main(){
	float m,h,BMI;
	scanf("%f%f",&m,&h);
	BMI=m/(h*h);
	if(BMI<18.5)
	 printf("Underweight");
	 else if(BMI<24)
	 printf("Normal");
	 else
	 printf("%.4f\nOverweight",BMI);
	return 0;
} 
