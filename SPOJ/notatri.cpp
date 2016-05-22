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
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

inline ll inp(){
	ll n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

inline int countGreater(int* start, int* end, int x){
	return ((end-start) - (upper_bound(start, end, x) - start));
}

int ar[2010];
int main(){
	int n = inp();
	while(n != 0){
		for(int i=0; i<n; i++)
			ar[i] = inp();
		sort(ar, ar+n); ll ans = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				ans+=(countGreater(ar+j+1, ar+n,ar[i]+ar[j]));
			}
		}
		printf("%lld\n", ans);
		n = inp();
	}
	return 0;
}