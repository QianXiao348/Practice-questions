#include<bits/stdc++.h>
using namespace std;
int w,n,ans=0;
int value[30010];
//��ֵ�ȴ�С��������  ����˫ָ���ж�
//��ָ��֮��>��ֵ������ָ������ߣ�����¼�� 
//��֮������� <��ֵ���� ˫ָ��ֱ���һ�� ����¼��
//ע�⵱���һ���Ǽ���ָ������ 
int main()
{
   	cin>>w>>n;
   	for(int i=1;i<=n;i++)
   	 cin>>value[i];
   	sort(value+1,value+n+1);
   	int r=n,l=1;
     while(l<=r){
   		   	if(value[l]+value[r]>w){
   		   		r--;
   		   		ans++;
				  }
			else {
				r--;
				l++;
				ans++;
			}
		  }
	   cout<<ans;
	return 0;
 } 
