#include<bits/stdc++.h>
using namespace std;
//ע������˺ϲ���Ĺ���ҲҪ�������� 
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    int a[10010];
    for(int i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
        ans+=a[i-1]+a[i];//����ϲ��� 
        a[i]=a[i-1]+a[i];//�ϲ������·Ž�����
		for(int j=i+1;j<n;j++){//Ȼ����в�������
			if(a[j-1]>a[j]) swap(a[j-1],a[j]);
			else break;//ֱ���źú����� 
		} 
	}
	printf("%d",ans);
	return 0;
}
