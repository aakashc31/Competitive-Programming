#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

void compute(string& s){
	sort(s.begin(), s.end());
	int n = s.length();
	vector<string> ans((1<<n),"");
	ans[1] = s[0];
	for(int i=1; i<n; i++){
		int currLen = (1<<i);
		for(int j=0; j<currLen; j++){
			ans[currLen+j] = ans[j];
			ans[currLen+j].pb(s[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for(int i=1; i<ans.size(); i++)
		cout << ans[i] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t, n; cin >> t;
	string st;
	while(t--){
		cin >> n >> st;
		compute(st);
	}
	return 0;
}