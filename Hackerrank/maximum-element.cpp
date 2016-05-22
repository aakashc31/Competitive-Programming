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
	int n; cin >> n;
	vi v(n); int idx = 0, type, x;
	stack<int> S;
	for(int i=0; i<n; i++){
		cin >> type;
		if(type == 1){
			cin >> x;
			v[idx++] = x;
			if(idx == 1)
				S.push(0);
			else{
				int k = v[idx-1] > v[S.top()] ? idx-1 : S.top();
				S.push(k);
			}
		}
		else if(type == 2){
			idx--;
			S.pop();
		}
		else{
			cout << v[S.top()] << endl;
		}
	}
	return 0;
}