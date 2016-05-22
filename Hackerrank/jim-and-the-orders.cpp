#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main(){
	int n;
	cin >> n;
	vector<pii> v(0);
	for(int i=0; i<n; i++){
		int a,b;
		cin >> a >> b;
		pii p = make_pair(a+b, i+1);
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n; i++)
		cout << v[i].second << " ";
	return 0;
}