#include<stdio.h>
int main(){
	int a[7][2],i,j,sum[7],sun,b[7]={0},count=0;
	for(i=0;i<7;i++){
		sun=0;
	 for(j=0;j<2;j++){
	  scanf("%d",&a[i][j]); 
	  sun+=a[i][j];  //����ÿ�첹ϰ��ʱ��� 
	  }
	  sum[i]=sun;  //��ÿ�첹ϰ��ʱ�丳��sum[i]����¼ 
     }
     for(i=0;i<7;i++){
     	if(sum[i]>8){ //��b[i]����¼���в����˵�ʱ�� 
     	b[i]=sum[i];
     	count=1;    //count������ʶ���ڲ����˵ı�־ 
	 }
    }
    if(count==0)
	printf("0");
	else{
		int max=b[0],flag; 
		for(i=0;i<7;i++){ //����һ������˵�ʱ�����αȽ�
			if(max<b[i]){ //�������и�����ʱ��ʱ�������¸�ֵ 
				max=b[i];
				flag=i; //ÿ�θ�ֵ������±��¼���� 
			}
		}
		printf("%d",flag+1);
	}
	return 0;
}
