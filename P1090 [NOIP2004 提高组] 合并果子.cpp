#include<bits/stdc++.h>
using namespace std;
//注意别忘了合并后的果子也要参与排序 
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
        ans+=a[i-1]+a[i];//计算合并后 
        a[i]=a[i-1]+a[i];//合并后重新放进数组
		for(int j=i+1;j<n;j++){//然后进行插入排序
			if(a[j-1]>a[j]) swap(a[j-1],a[j]);
			else break;//直到排好后跳出 
		} 
	}
	printf("%d",ans);
	return 0;
}
