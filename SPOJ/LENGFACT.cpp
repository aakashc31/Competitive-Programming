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

#define PI 3.141592653589793

//computes the number of digits in factorial(n)
ll kamenetsky(ll n){
	double ans = log(2*PI) - 2*n + (2*n+1)*log(n);
	ans /= log(10);
	ans *= 0.5;
	return ceil(ans);
}

int main(){
	ll t,n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n==1 || n==0){
			cout << 1 << endl;
			continue;
		}
		cout << kamenetsky(n) << endl;
	}
	return 0;
}