#include<stdio.h>
#include<math.h>
int main()
{
    float x1,x2,x3,y1,y2,y3,dis1,dis2,dis3,c;
    scanf("%f %f\n%f %f\n%f %f",&x1,&y1,&x2,&y2,&x3,&y3);
    dis1=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    dis2=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
    dis3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
    c=dis1+dis2+dis3;
    printf("%.2f",c);
    return 0;
}
