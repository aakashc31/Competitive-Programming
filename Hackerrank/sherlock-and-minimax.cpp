#include <bits/stdc++.h>
using namespace std;

int main(){
	int ar[100];
	int n,p,q;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	cin >> p >> q;
	sort(ar, ar+n);
	int low = lower_bound(ar,ar+n,p);
	int high = n - upper_bound(ar,ar+n,q); //number of elements greater than q

	if(p > ar[n-1])
		cout << q << endl;
	else if(q < ar[0])
		cout << p << endl;
	else{

	}
}