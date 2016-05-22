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
typedef long long int lli;


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

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
int numPrimes = 168;

#define maxN 1000000

int dp[1000001];
int firstPrimeDiv[1000001];

void sieve(){
	bitset<1000001> isPrime;
	isPrime.set();
	for(ll i=2; i<=maxN; i++){
		if(!isPrime[i])
			continue;
		firstPrimeDiv[i] = 1;
		for(ll j=i*i; j<=maxN; j+=i){
			isPrime[j] = 0;
			firstPrimeDiv[j] = i;
		}
	}
}

void precompute(){
	dp[1] = 1;
	dp[3] = dp[2] = 2;
	for(int i=4; i<=maxN; i++){
		if(firstPrimeDiv[i] == 1){
			dp[i] = 2;
			continue;
		}
		int divisor = firstPrimeDiv[i];
		int n = i;
		int power = 0;
		while(n % divisor == 0){
			power++;
			n/=divisor;
		}

		dp[i] = (power+1)*dp[n];

	}
}

int countDivisors(int n){
	int power = 0,ans = 1;
	for(int i=2; i*i <= n; i++){
		power = 0;
		while(n%i==0){
			power++;
			n /= i;
		}
		ans *= (1+power);
	}
	if(n > 1)
		ans = (ans<<1);
	return ans;
}

int main(){
	sieve();
	precompute();
	int t,a,b; 
	t = inp();
	while(t--){
		a = inp();
		b = inp();
		// printf("%d\n", dp[__gcd(a,b)]);
		printf("%d\n", countDivisors(__gcd(a,b)));
	}
	return 0;
}