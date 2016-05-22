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

double dp[100000];

void pre(){
	dp[0] = 0, dp[1] = 0;
	for(int i=2; i<100000; i++)
		dp[i] = dp[i-1] + log10(i);
}

int main(){
	pre();
	ll t,n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n==1 || n==0){
			cout << 1 << endl;
			continue;
		}
		cout << (ll)(dp[n]+1) << endl;
	}
	return 0;
}