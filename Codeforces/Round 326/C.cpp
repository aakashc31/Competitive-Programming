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

const int maxn = 10000100;
int w[maxn];

int main(){
	int n = inp(), a;
	f(i,n){
		a = inp();
		w[a]++;
	}
	int ans = 0;
	f(i,maxn){
		if(w[i]&1){
			ans++;
			w[i]--;
		}
		if(w[i]==0)
			continue;
		for(int j=1; j<32; j++){
			if((1<<j)&w[i]){
				w[i+j]++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}