#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

int main(){
	vi v;
	int ar[1000];
	int n;
	cin >> n;
	for(int i=0; i<n; i++) cin >> ar[i];
	for(int i=0; i<n; i++){
		f(j,n){
			v.pb(__gcd(ar[i], ar[j]));
		}
	}
	sort(v.begin(), v.end());
	f(i,v.size())
		cout << v[i] << " ";
	cout << endl;
	// set<int> s;
	// s.insert(1);
	// s.insert(2);
	// set<int>::iterator it = s.end();
	// it--;
	// it--;
	// cout << *(it) << endl;
	return 0;
}