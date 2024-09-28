#include <stdio.h>
#include<math.h>
int main()
{
	int S,V;
	scanf("%d%d",&S,&V);
	int tWalk=ceil(1.0*S/V)+10; //时间要向上取整不然会迟到 
	int tBefore=60*(24+8)-tWalk;//计算到前一天0点时间 
	int a=(tBefore/60)%24;//计算小时 
	int b=tBefore%60;//计算分钟 
	printf("%02d:%02d\n",a,b);
	return 0;
}
