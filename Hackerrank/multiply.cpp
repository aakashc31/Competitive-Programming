#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define getcx 			getchar//_unlocked
inline ll inp(){
	ll n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

const ll modulo = 1e9+7;
#define maxn 1000001

vi primes;
vpii Factors[maxn];
void sieve(){
	bitset<maxn> b; b.set();
	for(int i=2; i<maxn; i++){
		if(!b[i])
			continue;
		primes.pb(i);
		for(ll j = i*1ll*i; j < maxn; j+=i)
			b[j] = false;
	}
}

void factorize(){
	Factors[1].pb(mp(1,1)); Factors[2].pb(mp(2,1));
	for(int n=3; n<maxn; n++){
		bool isPrime = false; ll p=0;
		for(int i=0; i<primes.size();i++){
			p = primes[i];
			if(p*p > n){
				isPrime = true;
				break;
			}
			if(n % p == 0)
				break;
		}
		if(isPrime)
			Factors[n].pb(mp(n,1));
		else{
			Factors[n] = Factors[n/p];
			if((n/p) % p != 0)
				Factors[n].pb(mp(p,1));
			else
				Factors[n][Factors[n].size()-1].second++; //p is the smallest prime factor of n, hence at last
		}
	}
}

ll power_mod(ll n, ll p){
	if(p == 0)
		return 1;
	ll sq = n, ret=1;
	while(p != 0){
		if(p&1)
			ret = (ret * sq) % modulo;
		sq = (sq*sq) % modulo;
		p = (p>>1);
	}
	return ret;
}

ll inv[maxn];
void computeInverse(){
	for(int i=0; i<primes.size(); i++){
		inv[primes[i]-1] = power_mod(primes[i]-1, modulo-2);
	}
	// inv[1] = 1;
	// ll p = modulo;
	// for(int i=2; i<maxn; i++)
	// 	inv[i] = ((p - p/i)*inv[p%i])%p;
}

void pre(){
	sieve(); factorize(); computeInverse();
}
void testFactorize(){
	while(1){
		int n; cin >> n; int k = Factors[n].size();
		for(int i=0; i<k; i++){
			cout << Factors[n][i].first << "^" << Factors[n][i].second;
			if(i!=k-1)
				cout << " * ";
		}
		cout << endl;
	}
}


ll computeSumOfDivisors(unordered_map<int,int>& M){
	ll ans = 1, temp = 0, n, p;
	for(unordered_map<int,int>::iterator it = M.begin(); it != M.end(); it++){
		n = it->first, p = it->second;
		if(n==1) continue;
		// cout << "p = " << n << " alpha = " << p << endl;
		temp = (power_mod(n,p+1) - 1 + modulo) % modulo;
		temp = (temp * inv[n - 1]) % modulo;
		ans = (ans * temp) % modulo;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	pre();
	testFactorize();
	int n,q,x; cin >> n >> q;
	unordered_map<int,int> M;
	for(int i=0; i<Factors[n].size(); i++)
		M[Factors[n][i].first] = Factors[n][i].second;
	unordered_map<int,int>::iterator it;
	while(q--){
		cin >> x;
		vpii& xf = Factors[x];
		for(int i=0; i<xf.size();i++){
			// cout << xf[i].first << ", " << xf[i].second << endl;
			it = M.find(xf[i].first);
			if(it == M.end())
				M[xf[i].first] = xf[i].second;
			else
				M[xf[i].first] = it->second + xf[i].second;
		}
		cout << computeSumOfDivisors(M) << endl;
	}
	return 0;
}