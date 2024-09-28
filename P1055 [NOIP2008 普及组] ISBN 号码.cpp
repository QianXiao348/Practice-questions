#include<stdio.h>
int main()
{
	char a,b,c,d,e,f,g,h,i,j;
	int disc;
	scanf("%c-%c%c%c-%c%c%c%c%c-%c",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
	disc=((a-'0')*1+(b-'0')*2+(c-'0')*3+(d-'0')*4+(e-'0')*5+(f-'0')*6+(g-'0')*7+(h-'0')*8+(i-'0')*9)%11;
	if(disc==10&&j=='X'||disc==j-'0')
	 printf("Right\n");
	 else
	 printf("%c-%c%c%c-%c%c%c%c%c-%c",a,b,c,d,e,f,g,h,i,disc==10?'X':disc+'0');
	return 0;
 } 
