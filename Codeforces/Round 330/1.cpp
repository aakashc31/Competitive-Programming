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
	ios::sync_with_stdio(false);
	int n,m,a,b; cin >> n >> m;
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a >> b;
			ans += (a+b > 0) ? 1 : 0;
		}
	}
	cout << ans << endl;
	return 0;
}