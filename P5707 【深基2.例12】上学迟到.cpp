#include <stdio.h>
#include<math.h>
int main()
{
	int S,V;
	scanf("%d%d",&S,&V);
	int tWalk=ceil(1.0*S/V)+10; //ʱ��Ҫ����ȡ����Ȼ��ٵ� 
	int tBefore=60*(24+8)-tWalk;//���㵽ǰһ��0��ʱ�� 
	int a=(tBefore/60)%24;//����Сʱ 
	int b=tBefore%60;//������� 
	printf("%02d:%02d\n",a,b);
	return 0;
}
