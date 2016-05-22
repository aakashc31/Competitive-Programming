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

vi primes;

int dp[4][8001];

void pre(){
	bitset<8001> isPrime;
	isPrime.set();
	for(int i=2; i<8001; i++){
		if(!isPrime[i])
			continue;
		primes.push_back(i);
		dp[0][i] = 1;
		for(int j = i*i; j<8001; j+=i)
			isPrime[j] = 0;
	}
	// cout << primes.size() << endl;
	int rep;
	for(int i=1; i<=3; i++){
		for(int j=2; j<=8000; j++){
			if(dp[i-1][j] == 0){
				continue;
			}
			for(int k=0; k<primes.size(); k++){
				rep = primes[k]|j;
				if(rep <= 8000)
					dp[i][rep] = 1;
			}
		}
	}
	// cout << "done" << endl;
}


int main(){
	pre();
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		if(dp[0][n] | dp[1][n] | dp[2][n] | dp[3][n])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}