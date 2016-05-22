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

struct mytuple{
	ll a; ll b; int i;
	mytuple(ll x,ll y,int z) : a(x), b(y), i(z) {}
	mytuple() {}
};

inline bool operator<(const mytuple& a, const mytuple& b){
	if(a.a * a.b == b.a * b.b)
		return a.i > b.i;
	return a.a * a.b < b.a * b.b;
}

priority_queue<mytuple> S;
mytuple ar[100010];
int ans[100010];

inline ll ceil_div(ll a, ll b){
	ll ret = a/b;
	if(ret * b == a)
		return ret;
	return ret+1;
}
int main(){
	ll n, k;
	n = inp(); k = inp();
	for(int i=0; i<n; i++){
		ar[i].a = inp();
	}
	f(i,n) ar[i].b = inp();
	f(i,n){
		S.push(mytuple(ar[i].a, ar[i].b, i));
	}
	mytuple curr, next;
	ll diff, cnt, moves;
	while(k > 0){
		curr = S.top();
		S.pop();
		next = S.top();
		diff = (curr.a * curr.b) - (next.a * next.b);
		// cout << "curr = " << curr.i << " next = " << next.i << endl;
		if(diff == 0){
			// cout << "Taking " << 1 << " from " << curr.i << endl;
			curr.a--;
			k--;
			S.push(curr);
		}
		else{
			// cnt = ceil_div(diff,curr.a);
			// cout << "diff = " << diff << endl;
			cnt = diff/curr.a;
			moves = min(cnt, k);
			curr.a -= moves;
			// cout << "Taking " << moves << " from " << curr.i << endl;
			k -= moves;
			S.push(curr);
		}
	}
	while(!S.empty()){
		curr = S.top();
		S.pop();
		ans[curr.i] = curr.a;
	}
	f(i,n) cout << ans[i] << " ";
	cout << endl;
	return 0;
}