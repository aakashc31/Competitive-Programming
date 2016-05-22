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

int ar[100000];

int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		f(i,n) cin >> ar[i];
		ll curr = 1, ans = 0;
		for(int i=1; i<n; i++){
			if(ar[i] >= ar[i-1])
				curr++;
			else{
				ans += (curr*(curr+1))/2;
				curr = 1;
			}
		}
		ans += (curr*(curr+1))/2;
		cout << ans << endl;
	}
	return 0;
}