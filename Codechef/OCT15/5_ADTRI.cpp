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

inline int inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}


bitset<5000001> isHyp;
inline void pre(){
	int maxN = 5000000,c, size = 0, iter = 0;
	isHyp.reset();
	for(int r = 2; r*r <= maxN; r++){
		for(int s = 1; s < r; s++){
			c = r*r + s*s;
			if(c>maxN)
				continue;
			else if(isHyp[c])
				continue;
			if(((r-s)&1) && (__gcd(r,s)==1)){
				if(c<=maxN && isHyp[c])
					continue;
				for(int temp = c; temp <= maxN; temp+=c){
					iter++;
					if(!isHyp[temp]){
						isHyp[temp] = 1;
						size++;
					}
				}
			}
		}
	}
}

int main(){
	pre();
	int t, n;
	t = inp();
	while(t--){
		n = inp();
		if(isHyp[n])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}