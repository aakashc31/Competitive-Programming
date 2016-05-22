#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
#define pb push_back
 
int func(){
	int n;
	cin >> n;
	vi v;
	for(int i=0; i<n; i++) v.pb(i+1);
	int start = 0;
	while(v.size() != 1){
		vi temp;
		for(int i=start; i<v.size(); i+=2){
			temp.pb(v[i]);
		}
		start = (start == 0) ? (v.size()&1) : ((~(v.size()))&1);
		v = temp;
	}
	cout << v[0] << endl;
	return 0;
}

int main(){
	while(1)
		func();
}