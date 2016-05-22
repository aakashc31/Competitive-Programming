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

inline int inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

vi primes;

void pre(){
	bitset<100001> b;
	b.set();
	for(ll i=2; i<=100000; i++){
		if(!b[i])
			continue;
		primes.pb(i);
		for(ll j = i*i; j <= 100000; j+=i)
			b[j] = 0;
	}
}

bool isPrime(int n){
	for(int i=2; i*i <= n; i++){
		if(n%i==0)
			return false;
	}
	return true;
}

pii goldbach(int x){
	f(i,primes.size()){
		f(j,primes.size()){
			if(primes[i] + primes[j] == x){
				return mp(primes[i], primes[j]);
			}
		}
	}
	return mp(-1,-1);
}

int main(){
	pre();
	int n;
	cin >> n;
	if(isPrime(n)){
		cout << 1 << endl;
		cout << n << endl;
		return 0;
	}
	if(isPrime(n-2)){
		cout << 2 << endl;
		cout << 2 << " " << n-2 << endl;
		return 0;
	}
	if(n%3 == 0 && isPrime(n/3)){
		cout << 3 << endl;
		cout << n/3 << " " << n/3 << " " << n/3 << endl;
		return 0;
	}
	int floorPrime = n-4;
	while(!isPrime(floorPrime)){
		floorPrime -= 2;
	}
	int rem = n - floorPrime;
	cout << 3 << endl;
	pii ans = goldbach(rem);
	cout << floorPrime << " " << ans.first << " " << ans.second << endl; 
	return 0;
}