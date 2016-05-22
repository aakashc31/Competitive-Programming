#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

ll ar[100000];


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n,m;
		cin >> n >> m;
		for(int i=0; i<n; i++)
			cin >> ar[i];
		set<ll> s;
		set<ll>::iterator it;
		s.insert(0);
		ll ans = 0, maxPref = 0, pref = 0;
		for(int i=0; i<n; i++){
			pref  = (pref + ar[i]) % m;
			maxPref = max(maxPref, pref);
			it = s.upper_bound(pref);
			if(it != s.end()){
				ll temp = pref - (*it) + m;
				maxPref = max(temp, maxPref);
			}
			s.insert(pref);
		}
		cout << maxPref << endl;
	}
	return 0;
}