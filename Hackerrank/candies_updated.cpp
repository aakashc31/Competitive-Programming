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

int ar[100010];

int dp[100010]; //dp[i] tells the length of longest decreasing sequence ending at i

int main(){
	int n = inp();
	ar[0] = inp();
	dp[0] = 1;
	for(int i=1; i<n; i++){
		ar[i] = inp();
		if(ar[i] < ar[i-1])
			dp[i] = dp[i-1] + 1;
		else
			dp[i] = 1;
	}
	int beg;
	for(int i=1; i<n; i++){
		if(dp[i] > 1){
			beg = i - dp[i] + 1;
			if(beg > 0 && ar[beg] == ar[beg-1])
				dp[i]++;
		}
	}
	ll ans = 1;
	ll curr = 1;
	for(int i=1; i<n; i++){
		if(ar[i] == ar[i-1]){
			curr = 1;
			ans += curr;
			// cout << "i = " << i << " curr = " << curr << " ans = " << ans << endl;
		}
		else if(ar[i] > ar[i-1]){
			curr++;
			ans += curr;
			// cout << "i = " << i << " curr = " << curr << " ans = " << ans << endl;

		}
		else{
			if(curr == 1){
				// ans += 1;
				ans += (dp[i]-1);
				// cout << "i = " << i << " curr = " << curr << " ans = " << ans << "dp[i-1] = " << dp[i-1] << endl;

			}
			else{
				curr = 1;
				ans++;
				// cout << "i = " << i << " curr = " << curr << " ans = " << ans << endl;

			}
		}
	}
	cout << ans << endl;
	return 0;
}