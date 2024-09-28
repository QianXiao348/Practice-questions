#include<stdio.h>
int main(){
	int a[7][2],i,j,sum[7],sun,b[7]={0},count=0;
	for(i=0;i<7;i++){
		sun=0;
	 for(j=0;j<2;j++){
	  scanf("%d",&a[i][j]); 
	  sun+=a[i][j];  //计算每天补习的时间和 
	  }
	  sum[i]=sun;  //将每天补习的时间赋给sum[i]来记录 
     }
     for(i=0;i<7;i++){
     	if(sum[i]>8){ //用b[i]来记录所有不高兴的时间 
     	b[i]=sum[i];
     	count=1;    //count用来辨识存在不高兴的标志 
	 }
    }
    if(count==0)
	printf("0");
	else{
		int max=b[0],flag; 
		for(i=0;i<7;i++){ //假设一个最不高兴的时间依次比较
			if(max<b[i]){ //当满足有更长的时间时进行重新赋值 
				max=b[i];
				flag=i; //每次赋值将最大下标记录下来 
			}
		}
		printf("%d",flag+1);
	}
	return 0;
}
