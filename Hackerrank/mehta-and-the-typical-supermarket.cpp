#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef unsigned long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

ll ar[17]; int n;
int d; ll L[101], R[101];
ll ans[101];

inline ll computeLCM(int& mask){
	ll a = 1;
	for(int i=0; i<n; i++){
		if(mask&(1<<i)){
			a = (a * (ar[i]/__gcd(a, ar[i])));
		}
	}
	return a;
}

void compute(){
	for(int mask = 1; mask < (1<<n); mask++){
		ll lcm = computeLCM(mask);
		if(__builtin_popcount(mask)&1){
			for(int i=0; i<d; i++)
				ans[i] += (R[i]/lcm - (L[i]-1)/lcm);
		}
		else{
			for(int i=0; i<d; i++)
				ans[i] -= (R[i]/lcm - (L[i]-1)/lcm);
		}
	}
	for(int i=0; i<d; i++)
		cout << ans[i] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	cin >> d;
	for(int i=0; i<d; i++){
		cin >> L[i] >> R[i];
	}
	compute();
	return 0;
}