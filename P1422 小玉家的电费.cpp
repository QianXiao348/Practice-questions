#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	double sum;
	if(x<=150) sum=x*0.4463;
    else if(x<=400) sum=(x-150)*0.4663+150*0.4463;
	else  sum=(x-400)*0.5663+250*0.4663+150*0.4463;
	printf("%.1f",sum);
	return 0;
}
