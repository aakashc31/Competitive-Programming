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

inline ll inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}



ll power_mod(ll n, ll p, ll modulo)
{
	if(p==0) return 1%modulo;
	ll a = 1, sq=n;
	while(p>0)
	{
		if(p&1) a =(a*sq)%modulo;
		sq = (sq*sq)%modulo;
		p = p>>1;
	}
	return a;
}


const ll modulo = 1e9 + 7;
vi primes;
map<int,int> others;

int primeIndex[1001];

void pre(){
	bitset<1001> b;
	b.set();
	for(int i=2; i<=1000; i++){
		if(!b[i])
			continue;
		primes.pb(i);
		primeIndex[i] = primes.size()-1;
		for(int j=i*i; j<=1000; j+=i)
			b[j] = 0;
	}
}

void factor(int n, vi& primePower){
	map<int,int>::iterator it;
	int cnt;
	for(int i=2; i*i <= n; i++){
		if(n%i == 0){
			cnt = 0;
			while(n%i == 0){
				n /= i;
				cnt++;
			}
			// cout << "i = " << i << " primeIndex[i] = " << primeIndex[i] << " cnt = " << cnt << endl;
			primePower[primeIndex[i]]+= cnt;
		}
	}
	if(n > 1){
		// cout << "Here " << endl;
		it = others.find(n);
		if(it == others.end())
			others[n] = 1;
		else
			it->second++;
	}
}

ll compute(vi& primePower){
	ll ans = 1, num, den, p, alpha;
	for(int i=0; i<primes.size(); i++){
		p = primes[i];
		alpha = primePower[i];
		if(alpha == 0)
			continue;
		num = power_mod(p, alpha+1, modulo);
		den = power_mod(p-1, modulo-2, modulo); //calc inverse
		num = (num - 1 + modulo) % modulo;
		num = (num * den) % modulo;
		ans = (ans * num) % modulo;
	}
	// cout << "ans = " << ans << endl;
	for(map<int,int>::iterator it = others.begin(); it!=others.end(); it++){
		num = power_mod(it->first, it->second + 1, modulo);
		// cout << "p = " << it->first << " alpha = " << it->second << endl;
		den = power_mod(it->first - 1, modulo-2, modulo);
		// cout << "num = " << num << " den = " << den << endl;
		num = (num - 1 + modulo) % modulo;
		num = (num * den) % modulo;
		ans = (ans * num) % modulo;
	}
	return ans;
}

int main(){
	pre();
	vi primePower(primes.size(), 0);
	ll n,q,x;
	n = inp(); q = inp();
	if(n>1)
		factor(n, primePower);
	f(i,q){
		x = inp();
		factor(x, primePower);
		cout << compute(primePower) << endl;
	}
	return 0;
}
