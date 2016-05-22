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

pii ar[110];
int main(){
	int t = inp(); int n;
	while(t--){
		n = inp();
		for(int i=0; i<n; i++){
			ar[i].first = inp(); ar[i].second = inp();
		}
		sort(ar, ar+n);
		priority_queue<int, vi, greater<int> > pq;
		int ans = 1; pq.push(ar[0].second);
		for(int i=1; i<n; i++){
			while(!pq.empty() && ar[i].first > pq.top())
				pq.pop();
			pq.push(ar[i].second);
			ans = max(ans, (int)pq.size());
		}
		printf("%d\n", ans);
	}
	return 0;
}