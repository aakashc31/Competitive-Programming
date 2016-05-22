#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t; string st;
	while(t--){
		cin >> st;
		stack<char> S; bool isBalanced = true; char ch;
		for(int i=0; i<st.size(); i++){
			ch = st[i];
			if(ch == '[' || ch == '{' || ch == '(')
				S.push(ch);
			else{
				char compCh = '(';
				if(ch == ']') compCh = '[';
				else if(ch == '}') compCh = '{';
				if(S.size() == 0 || S.top() != compCh){
					isBalanced = false;
					break;
				}
				S.pop();
			}
		}
		if(S.size())
			isBalanced = false;
		if(isBalanced)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}