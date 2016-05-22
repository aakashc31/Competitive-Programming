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


int W[10001];
int main(){
	int t,n;
	cin >> t;
	string ans, chef;
	while(t--){
		cin >> n;
		cin >> ans >> chef;
		f(i,n+1) cin >> W[i];
		int count = 0;
		f(i,n){
			if(ans[i] == chef[i])
				count++;
		}
		if(count < n)
			cout << *max_element(W, W+count+1) << endl;
		else
			cout << W[n] << endl;
	}
	return 0;
}