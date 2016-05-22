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

ll a[100000], p[100000]; 
int main(){
	int n;
	cin >> n;
	f(i,n){
		cin >> a[i] >> p[i];
	}
	ll cost = 0;
	ll currPrice = p[0], quantity = a[0];
	for(int i=1; i<n; i++){
		if(p[i] < currPrice){
			cost += (quantity * currPrice);
			currPrice = p[i];
			quantity = a[i];
		}
		else{
			quantity += a[i];
		}
	}
	cost += (quantity * currPrice);
	cout << cost << endl;
	return 0;
}