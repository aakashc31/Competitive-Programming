#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

int main(){
	int t; ll d,n;
	cin >> t;
	while(t--){
		cin >> d >> n;
		for(int i=0; i<d; i++)
			n = (n*(n+1))/2;
		cout << n << endl;
	}
	return 0;
}