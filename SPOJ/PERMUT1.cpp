#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx 			getchar//_unlocked
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

ll dp[13][99];

void pre(){
	// base case
	for(int k=1; k<=98; k++)
		dp[1][k] = 0;
	for(int n=1; n<=12; n++)
		dp[n][0] = 1;

	ll curr = 0;
	for(int n=2; n<=12; n++){
		for(int k=1; k<=98; k++){
			curr = 0;
			for(int i=0; i<n; i++){
				if(k-i < 0){
					goto outer;
				}
				curr += dp[n-1][k-i];
			}
			outer:
			// cout << "dp[" << n << "][" << k << "] = " << curr << endl;
			dp[n][k] = curr;
		}
	}
}

int main(){
	pre();
	int d,n,k;
	cin >> d;
	while(d--){
		cin >> n >> k;
		cout << dp[n][k] << endl;
	}
	return 0;
}