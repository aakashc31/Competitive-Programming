#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

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

bitset<1000001> flags;
int maxn = 1000000;

vector<int> primes;

void sieve(){
	flags.set(); //all true
	for(int j=2; j<=maxn; j++){
		if(!flags[j])
			continue;
		primes.push_back(j);
		ll prod = ((ll)j)*j;
		while(prod <= maxn){
			flags[prod] = 0;
			prod += j;
		}
	}
}

int main(){
	int t,n,a;
	t = inp();
	sieve();
	int* powers = new int[primes.size()];
	while(t--){
		n = inp();
		memset(powers, 0, 4*primes.size());
		for(int i=0; i<n; i++){
			a = inp();
			for(int j=0; j<primes.size();j++){
				if(a == 1)
					break;
				while(a % primes[j] == 0){
					powers[j]++;
					a /= primes[j];
				}
			}
		}
		ll ans = 1;
		for(int i=0; i<primes.size(); i++)
			ans *= (((ll)powers[i])+1);
		cout << ans << endl;
	}
	return 0;
}