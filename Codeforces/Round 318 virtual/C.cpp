#include <bits/stdc++.h>
using namespace std;

int reduce(int n){
	while(n%2 == 0)
		n/=2;
	while(n%3 == 0)
		n/=3;
	return n;
}

int main(){
	int n,a;
	int first;
	cin >> n >> first;
	first = reduce(first);
	bool ans = true;
	for(int i=0; i<n-1; i++){
		cin >> a;
		if(ans){
			a = reduce(a);
			if(a!=first)
				ans = false;
		}
	}
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
}