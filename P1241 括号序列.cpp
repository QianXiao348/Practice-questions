#include<bits/stdc++.h>
using namespace std;
stack <int> st;
bool ok[105];
int main(){
	string s;
	cin >> s;
	int len = s.length();
	for(int i = 0,k;i < len;i ++)
	{
		if(s[i] == ']')
		{
			if(st.empty()) continue;
			k = st.top();
			if(s[k] == '[') 
			{
				ok[k] = ok[i] = 1;
				st.pop();
			}
		}
		else if(s[i] == ')')
		{
			if(st.empty()) continue;
			k = st.top();
			if(s[k] == '(') 
			{
				ok[k] = ok[i] = 1;
				st.pop();
			}
		}
		else
			st.push(i);
	}
	for(int i = 0;i < len;i ++)
	{
		if(ok[i]) cout << s[i];
		else
		{
			if(s[i] == '(' || s[i] == ')') printf("()");
			else printf("[]");
		}
	}
	return 0;
}
