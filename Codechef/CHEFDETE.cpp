#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<bool> flags(n,true); int x;
	for(int i=0; i<n; i++){
		cin >> x;
		if(x) flags[x-1] = false;
	}
	for(int i=0; i<n; i++){
		if(flags[i])
			cout << i+1 << " ";
	}
	cout << endl;
	return 0;
}