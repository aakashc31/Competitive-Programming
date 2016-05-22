#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)

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

vi primes;

#define maxn 31624
void pre(){
	bitset<maxn> b;
	b.set();
	for(int i=2; i<maxn; i++){
		if(!b[i])
			continue;
		primes.pb(i);
		for(int j=i*i; j<maxn; j+=i)
			b[j] = 0;
	}
}

int main(){
	pre();
	int t,m,n; t = inp();
	bool isPrime;
	while(t--){
		m = inp(); n = inp();
		for(int i=m; i<=n; i++){
			if(i <= primes.back()){
				if(binary_search(primes.begin(), primes.end(), i))
					cout << i << endl;
				continue;
			}
			isPrime = true;
			for(int j=0; j<primes.size(); j++){
				if(i % primes[j] == 0){
					isPrime = false;
					break;
				}
				if(primes[j]*primes[j] > i)
					break;
			}
			if(isPrime)
				cout << i << endl;
		}
		cout << endl;
	}
	return 0;
}