#include<bits/stdc++.h>
using namespace std;
const int N = 2e4+10;
int A[N],B[N],n;
int C[N<<1];
bool D[N<<1];
int cnt=1;
long long ans;
int find(int x){
	int l=1,r=cnt;
	while(l<r){
		int mid=l+r>>1;
		if(C[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	int l,r;
    	cin>>A[i]>>B[i];
        C[cnt++]=A[i];
		C[cnt++]=B[i];   
	}
	sort(C+1,C+cnt+1);
	cout<<cnt<<" ";
	cnt=unique(C+1,C+cnt+1)-C;
    cout<<cnt<<" ";
	for(int i=1;i<=n;i++){
		int a=find(A[i]),b=find(B[i]);
		for(int j=a;j<b;j++)
		 D[j]=1;
	}
	for(int i=1;i<=cnt;i++){
		if(D[i]==1)
		ans+=(C[i+1]-C[i]);
	}
	cout<<ans;
	return 0;
}

