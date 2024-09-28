#include<bits/stdc++.h>
using namespace std;
//先按结束时间进行排序 然后从0开始找到最短的结束时间
//并进行标记 再从标记开始找最短时间 一直递推到结束 
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
	int mark=0;//从头开始 定位 
	for(int i=0;i<n;i++){
		if(mark<=a[i].start){ //从定位开始 
			ans++;//找到结束最短的时间并且进行定位 
			mark=a[i].end;
		}
	}
	printf("%d",ans);
	return 0;
}
