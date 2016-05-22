#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int compute(string& st){
	vi v(0);
	int curr = 0;
	for(int i=0; i<st.length(); i++){
		if(st[i] < 'a' || st[i] > 'z'){
			if(curr != 0)
				v.pb(curr);
			curr = 0;
		}
		else{
			curr++;
		}
	}
	if(curr != 0)
		v.pb(curr);

	int ans = 1; curr = 1;
	for(int i=1; i<v.size(); i++){
		if(v[i] == v[i-1])
			curr++;
		else
			curr = 1;
		ans = max(ans, curr);
	}
	return ans;
}

int main(){
	// ios::sync_with_stdio(false);
	string st; int t; cin >> t;
	getchar();
	while(t--){
		// cout << "1 " << endl;
		getline(cin, st);
		if(st.size() == 0){
			t++; continue;
		}
		// cout << st;
		// st += "\n";
		// cout << "2 st = " << st << endl;
		cout << compute(st) << endl;
	}
	return 0;
}