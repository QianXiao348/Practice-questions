#include<bits/stdc++.h>
using namespace std;
int ans[30],n,m1[30],m2[30],m3[30],mark=0;
void backtracking(int x){//x����ǰ�ݹ���� 
	 if(x>n){
	    mark++;//��¼�𰸽ⷨ 
	    if(mark<4){//���ǰ3�ֽⷨ 
	    	for(int i=1;i<=n;i++)
	    	 printf("%d ",ans[i]);
	    	cout<<endl;
		}
		return;
	 }
	 for(int i=1;i<=n;i++){
	 	if(m1[i]||m2[i+x]||m3[x-i+n])
	 	 continue; 
	 	ans[x]=i;
		 m1[i]=1;//���б�� 
		 m2[i+x]=1;
		 m3[x-i+n]=1; 
        backtracking(x+1);//�ݹ���� 
         m1[i]=0; //���л���
		 m2[i+x]=0;
		 m3[x-i+n]=0;
		 }
}
int main(){
     scanf("%d",&n);
     backtracking(1);
     printf("%d",mark);
	return 0;
}

