#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
typedef long long int lli;

int phi(int n){
	vector<int> v;
	int c = n, cpy = n;
	int i=2;
	while(i*i <= n){
		if(n%i == 0){
			v.push_back(i);
			while(n%i==0)
				n/=i;
		}
		i++;
	}
	if(n!=1) v.push_back(n);
	for(int j=0; j<v.size(); j++){
		// cout << v[j] << " ";
		c = (c*(v[j]-1))/v[j];
	}
	// cout << "\nphi(" << cpy << ") = " << c << endl;
	return c;
}

int main(){
	int x,y;
	int ans = 0;
	cin >> x >> y;
	while(x<=y){
		int n = x;
		if(n % phi(n) == 0){
			// cout << n << endl;
			ans++;
		}
		x++;
	}
	cout << ans << endl;
	return 0;
}