#include<bits/stdc++.h>
using namespace std;
int n,s,a,b,ans=0;
struct apple{
	int x,y;
}nums[5010];
bool cnm(apple as,apple ac){
	return as.y<ac.y;
}
int main()
{
    cin>>n>>s>>a>>b;
    for(int i=0;i<n;i++){
    	cin>>nums[i].x>>nums[i].y;
	}
	sort(nums,nums+n,cnm);
	for(int i=0;i<n;i++){
		if(nums[i].x<=a+b){
			if(s>=nums[i].y){
				ans++;
				s-=nums[i].y;
			}
			else if(s<0) break;
		}
	}
	cout<<ans;
	return 0;
 } 
