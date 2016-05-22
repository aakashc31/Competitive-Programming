#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define getcx getchar//_unlocked
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

inline ll compute(ll n){
	ll ans = 3*((n*(n-1))/2) + 5 + 4*(n-1);
	return ans;
}

int main(){
	int n = inp();
	while(n != 0){
		printf("%lld\n", compute(n));
		n = inp();
	}
	return 0;
}