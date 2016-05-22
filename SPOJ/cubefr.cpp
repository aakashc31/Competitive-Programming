#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

#define getcx 			getchar//_unlocked
inline ll inp(){
	ll n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}
const int maxn = 1e6+10;
int ans[maxn];
vi primes;
inline bool isCubeFree(int n){
	int curr;
	for(int i=0; i<primes.size(); i++){
		curr = primes[i]*primes[i]*primes[i];
		if(curr > n)
			return true;
		if(n % curr == 0)
			return false;
	}
	return true;
}

void pre(){
	bool flag[100];int n = 99;
	memset(flag, 1, sizeof flag);
	for(int i=2; i<=n; i++){
		if(!flag[i])
			continue;
		primes.pb(i);
		for(int j = i*i; j<=n; j+=i)
			flag[j] = false;
	}
	int cnt = 2; ans[1] = 1;
	for(int i=2; i<=1e6; i++){
		ans[i] = -1;
		if(isCubeFree(i))
			ans[i] = cnt++;
	}
}

int main(){
	pre();
	int T = inp(),n;
	for(int t=0; t<T; t++){
		n = inp();
		if(ans[n] == -1)
			printf("Case %d: Not Cube Free\n", t+1);
		else
			printf("Case %d: %d\n",t+1,ans[n]);
	}
	return 0;
}