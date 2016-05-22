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

ll n,k;
ll a[100010], b[100010];
const ll inf = 1e18;

bool requiredDays(ll c){
	int req = 0;
	ll t,steps;
	for(int i=0; i<n; i++){
		t = max(0ll, a[i]*b[i] - c);
		steps = t/b[i];
		if(t%b[i]) steps++;
		req+=steps;
		if(req>k)
			return false;
	}
	return true;
}

int main(){
	n = inp(); k = inp();
	f(i,n) a[i] = inp();
	f(i,n) b[i] = inp();
	ll low = 0, high = inf, mid;
	while(low < high){
		mid = low + (high-low)/2;
		if(requiredDays(mid))
			high = mid;
		else
			low = mid+1;
	}
	ll t,steps;

	f(i,n){
		t = max(0ll, a[i]*b[i] - low);
		steps = t/b[i];
		if(t%b[i]) steps++;
		k -= steps;
		a[i] -= steps;
	}

	f(i,n){
		if(a[i] > 0 && a[i]*b[i] == low && k > 0){
			k--;
			a[i]--;
		}
	}

	f(i,n) cout << a[i] << " ";
	cout << endl;
	return 0;
}