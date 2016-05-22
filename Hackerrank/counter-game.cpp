#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		int ctr = 0;
		ll copy = n;
		while(!(copy&1)){
			copy = copy >> 1;
			ctr++;
		}
		int s = __builtin_popcountll(n) - 1 + ctr;
		if(s%2==0)
			cout << "Richard" << endl;
		else
			cout << "Louise" << endl;
	}
	return 0;
}