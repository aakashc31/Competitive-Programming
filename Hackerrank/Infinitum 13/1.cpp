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
	int t,a,b,n;
	cin >> t;
	while(t--){
		cin >> a >> b;
		if(a==0 || b==0){
			cout << "First" << endl;
			continue;
		}
		n = a+b+1;
		if(n&1)
			cout << "Second" << endl;
		else
			cout << "First" << endl;
	}
}