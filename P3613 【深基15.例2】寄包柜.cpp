#include<cstdio>
#include<iostream> 
#include<map>//引用STL里的map库
using namespace std;
map<int,map<int,int> > a;//建立二维映射
int main(){
	int n,q,x,y,k,z;
    cin>>n>>q;//输入寄包柜个数及询问次数
    for(int i=1;i<=q;++i){//循环q次
        scanf("%d%d%d",&k,&x,&y);//先输入k,x,y
        if(k==1){//存放操作
            scanf("%d",&z);//继续输入
            a[x][y]=z;//建立一次映射
        }
        else{//查询操作
            printf("%d\n",a[x][y]);//直接输出所映射的值
        }
    }
	return 0;
} 
