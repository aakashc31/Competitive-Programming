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

multiset<int> s;

int main(){
	int n,a,curr;
	cin >> n;
	for(int i=0; i<n*n; i++){
		cin >> a;
		s.insert(a);
	}

	if(n == 1){
		multiset<int>::iterator it = s.end();
		it--;
		cout << *it << endl;
		return 0;
	}

	multiset<int>::iterator it = s.end();
	vi v;
	while(s.size() > 1){
		it = s.end(); it--;
		curr = *it;
		s.erase(it);
		f(i,v.size()){
			s.erase(s.find(__gcd(curr, v[i])));
			s.erase(s.find(__gcd(curr, v[i])));
		}
		v.pb(curr);
	}

	f(i,v.size())
		cout << v[i] << " ";
	cout << endl;

	return 0;
}