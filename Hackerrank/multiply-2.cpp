#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const ll modulo = 1e9+7;
#define maxn 1000001

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
int numPrimes = 168;
vpii Factors[maxn];

void factorize(){
	Factors[1].pb(mp(1,1)); Factors[2].pb(mp(2,1));
	for(int n=3; n<maxn; n++){
		bool isPrime = true; ll p=0;
		for(int i=0; i<numPrimes;i++){
			p = primes[i];
			if(p*p > n)
				break;
			if(n % p == 0){
				isPrime = false;
				break;
			}
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
	inv[1] = 1;
	ll p = modulo;
	for(int i=2; i<maxn; i++)
		inv[i] = ((p - p/i)*inv[p%i])%p;
}

inline ll divSum(ll p, ll alpha){
	ll temp = (power_mod(p,alpha+1) - 1 + modulo) % modulo;
	temp = (temp * inv[p-1]) % modulo;
	return temp;
}

ll divSumChange(ll p, ll alphaOld, ll alphaNew){
	ll d1 = divSum(p, alphaOld);
	ll d2 = divSum(p, alphaNew);
	if(d1 < maxn)
		d1 = inv[d1];
	else
		d1 = power_mod(d1, modulo-2);
	d2 = (d2 * d1) % modulo;
	return d2;
}

int main(){
	ios::sync_with_stdio(false);
	factorize();
	computeInverse();
	int n,q,x; cin >> n >> q;
	ll ans = 1;
	vpii& v = Factors[n];
	unordered_map<int,int> M; unordered_map<int,int>::iterator it;
	for(int i=0; i<v.size(); i++){
		if(v[i].first != 1){
			M[v[i].first] = v[i].second;
			ans = (ans * divSum(v[i].first, v[i].second)) % modulo;
		}
	}
	while(q--){
		cin >> x;
		vpii& xf = Factors[x];
		for(int i=0; i<xf.size();i++){
			if(xf[i].first == 1)
				continue;
			it = M.find(xf[i].first);
			if(it == M.end()){
				M[xf[i].first] = xf[i].second;
				ans = (ans * divSum(xf[i].first, xf[i].second)) % modulo;
			}
			else{
				ans = (ans * divSumChange(xf[i].first, it->second, it->second + xf[i].second)) % modulo;
				M[xf[i].first] = it->second + xf[i].second;
			}
		}
		cout << ans << endl;
	}
	return 0;
}