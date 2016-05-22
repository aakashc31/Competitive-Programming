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

ll dp[10][301][100]; //dp[i][k][j] means number of valid ways of taking k steps in i'th dimension if initially you are at j
ll finalDP[10][301]; //finalDP[i][j] means number of ways you can take j steps in first dimensions 0...i

int n,m; //num dimensions, num steps
int x[10], d[10]; //co-ords, dimensions

const ll modulo = 1000000007;

ll comb[301][301];

void pre(){
	for(int i=0; i<=300; i++){
		comb[1][i] = 0;
		comb[i][0] = 1;
	}
	comb[1][1] = 1;
	for(int i=2; i<=300; i++){
		for(int j=1; j<=i; j++){
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%modulo;
		}
	}
}

ll compute(){
	//fill dp array
	for(int i=0; i<n; i++){
		for(int k=0; k<=m; k++){
			for(int j=0; j<d[i]; j++){
				if(k==0)
					dp[i][k][j] = 1;
				else if(j==0)
					dp[i][k][j] = (j+1 < d[i]) ? dp[i][k-1][j+1] : 0;
				else if(j == d[i]-1)
					dp[i][k][j] = (j-1 >= 0) ? dp[i][k-1][j-1] : 0;
				else
					dp[i][k][j] = (dp[i][k-1][j+1] + dp[i][k-1][j-1])%modulo;
			}
		}
	}

	//fill finalDP array
	for(int i=0; i<n; i++){
		for(int k=0; k<=m; k++){
			if(i == 0){
				finalDP[0][k] = dp[0][k][x[0]];
				continue; 
			}
			else if(k == 0){
				finalDP[i][0] = 1;
				continue;
			}
			ll sum = 0;
			for(int j=0; j<=k; j++){
				sum += (((finalDP[i-1][k-j] * dp[i][j][x[i]])%modulo)*comb[k][j])%modulo;
				sum %= modulo;
			}
			finalDP[i][k] = sum;
		}
	}

	return finalDP[n-1][m];
}

int main(){
	pre();
	int t = inp();
	while(t--){
		n = inp(); m = inp();
		f(i,n) x[i] = inp() - 1;
		f(i,n) d[i] = inp();
		cout << compute() << endl;
	} 
	return 0;
}