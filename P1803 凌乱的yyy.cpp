#include<bits/stdc++.h>
using namespace std;
//�Ȱ�����ʱ��������� Ȼ���0��ʼ�ҵ���̵Ľ���ʱ��
//�����б�� �ٴӱ�ǿ�ʼ�����ʱ�� һֱ���Ƶ����� 
struct match{
	int start,end;
}a[1000010];
bool cnm(match b,match c){
	return b.end<c.end;
}
int main()
{
	int n,ans;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	 scanf("%d%d",&a[i].start,&a[i].end);
	}
	sort(a,a+n,cnm);
	int mark=0;//��ͷ��ʼ ��λ 
	for(int i=0;i<n;i++){
		if(mark<=a[i].start){ //�Ӷ�λ��ʼ 
			ans++;//�ҵ�������̵�ʱ�䲢�ҽ��ж�λ 
			mark=a[i].end;
		}
	}
	printf("%d",ans);
	return 0;
}
