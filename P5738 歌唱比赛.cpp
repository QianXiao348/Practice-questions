#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m; 
int main()
{
	 cin>>n>>m;
	 double max_s=-1;
	 while(n--){
	 	double sum=0,max_s1=-1,min_s1=11;
	 	for(int i=0;i<m;i++){
	 		double t;
	 		cin>>t;
	 		sum+=t;
	 		max_s1=max(max_s1,t);
	 		min_s1=min(min_s1,t);
		 }
		sum=sum-max_s1-min_s1;
		max_s=max(max_s,1.0*sum/(m-2));
	 }
	 printf("%.2lf\n",max_s);
	return 0;
}

