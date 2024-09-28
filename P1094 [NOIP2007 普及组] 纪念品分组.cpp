#include<bits/stdc++.h>
using namespace std;
int w,n,ans=0;
int value[30010];
//价值先从小到大排序  采用双指针判断
//当指针之和>价值上限右指针向后走，并记录答案 
//反之若满足就 <价值上限 双指针分别走一步 并记录答案
//注意当最后一个是即两指针相遇 
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
