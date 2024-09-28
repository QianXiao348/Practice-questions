#include<bits/stdc++.h>
using namespace std;
int ans[30],n,m1[30],m2[30],m3[30],mark=0;
void backtracking(int x){//x代表当前递归层数 
	 if(x>n){
	    mark++;//记录答案解法 
	    if(mark<4){//输出前3种解法 
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
		 m1[i]=1;//进行标记 
		 m2[i+x]=1;
		 m3[x-i+n]=1; 
        backtracking(x+1);//递归调用 
         m1[i]=0; //进行回溯
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

