#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked


typedef long long int ll;

ll comdiv(int A, int B){
	int a = min(A,B);
	int b = max(A,B);
	ll ans = 0;
	for(int i=1; i<=A; i++){
		if((a%i==0) && (b%i==0))
			ans++;
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		cout << comdiv(a,b) << endl;
	}
	return 0;
}