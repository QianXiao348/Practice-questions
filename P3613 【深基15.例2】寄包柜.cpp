#include<cstdio>
#include<iostream> 
#include<map>//����STL���map��
using namespace std;
map<int,map<int,int> > a;//������άӳ��
int main(){
	int n,q,x,y,k,z;
    cin>>n>>q;//����İ��������ѯ�ʴ���
    for(int i=1;i<=q;++i){//ѭ��q��
        scanf("%d%d%d",&k,&x,&y);//������k,x,y
        if(k==1){//��Ų���
            scanf("%d",&z);//��������
            a[x][y]=z;//����һ��ӳ��
        }
        else{//��ѯ����
            printf("%d\n",a[x][y]);//ֱ�������ӳ���ֵ
        }
    }
	return 0;
} 
