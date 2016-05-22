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

vector<int> primes;

inline void precompute(){
	bitset<32001> isPrime;
	isPrime.set();
	int maxNum = 32000;
	for(int i=2; i<=maxNum; i++){
		if(!isPrime[i])
			continue;
		primes.pb(i);
		for(int j=i*i; j<=maxNum; j+=i)
			isPrime[j] = 0;
	}
}

inline ll getNumDiv(int num){
	ll ans = 1, ncount = 0;
	for(int i=0; i<primes.size();i++){
		if(num == 1 || primes[i] > num)
			break;
		ncount = 0;
		while(num % primes[i] == 0){
			ncount++;
			num /= primes[i];
		}
		ans *= (ncount+1);
	}
	if(num > 1)
		ans *= 2;
	return ans;
}


int main(){
	precompute();
	int a,b,n;
	cin >> a >> b >> n;
	int ans = 0;
	for(int i=a; i<=b; i++){
		if(getNumDiv(i) == n)
			ans++;
	}
	cout << ans << endl;
	return 0;
}