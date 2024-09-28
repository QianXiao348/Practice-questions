#include<bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0),ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int>PII;
const int dx[]={-1,0,1,0,-1,1,1,-1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int N = 1e5+10;
char ch[N];
int n = 0;
void cal(int b)
{
	int w = 0, l = 0;
	for (int i = 0; i < n; i++) {
		if (ch[i] == 'W')
			w++;
		else if (ch[i] == 'L')
			l++;
		if (max(w, l) >= b && abs(w - l) >= 2) {
			cout << w << ":" << l << endl;
			w = l = 0;
		}
	}
	cout << w << ":" << l << endl;
}
void solve(){
	char s;
	while (cin >> s && s != 'E')
	{
		if (s == 'W' || s == 'L')
			ch[n++] = s;
	}
	cal(11);
	cout << endl;
	cal(21);
}
int main(){
	PASE;
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}


