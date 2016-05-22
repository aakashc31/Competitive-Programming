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

const int maxn = 1e3;
ll ans[maxn+1];

void pre(){
	ans[1] = 5;
	for(ll i = 2; i <= maxn; i++)
		ans[i] = ans[i-1] + 4 + 3*(i-1);
}

int main(){
	pre();
	int n = inp();
	while(n != 0){
		printf("%lld\n", ans[n]);
		n = inp();
	}
	return 0;
}