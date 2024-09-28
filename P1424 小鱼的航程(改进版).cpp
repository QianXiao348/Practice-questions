#include<iostream>
using namespace std;
int main()
{
	int x,n,sum=0;
	cin >> x >> n;
	for(int i=1;i<=n;i++){
		if(x!=6&&x!=7) sum+=250;
	    if(x==7) x=1;
	    else x++;//不等于7的情况都往前走一天 
	}
	cout<<sum;
	return 0;
}
