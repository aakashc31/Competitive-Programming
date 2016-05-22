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

#define parent 	first
#define rank	second

const int maxn = 50010;
set<int> S[maxn];

// xRoot is the new leader
inline void merger(int xRoot, int yRoot){
	S[xRoot].insert(S[yRoot].begin(), S[yRoot].end());
	for(set<int>::iterator it = S[yRoot].begin(); it != S[yRoot].end(); it++){
		S[*it].insert(xRoot);
	}
	S[yRoot].clear();
}

class DisjointSet{
private:
	pii* ar;
	int size;
public:
	DisjointSet(int n){
		size = n;
		ar = new pii[n];
		for(int i=0; i<n; i++) ar[i] = mp(i,0);	
	}
	// uses path compression
	int Find(int n){
		assert((n < size) && (n>=0));
		if(ar[n].parent != n)
			ar[n].parent = Find(ar[n].parent);
		return ar[n].parent;
	}
	// uses Union by rank
	void Union(int x, int y){
		assert((x < size) && (x>=0));
		assert((y < size) && (y>=0));
		int xRoot = Find(x);
		int yRoot = Find(y);
		if(xRoot == yRoot)
			return;
		if(ar[xRoot].rank < ar[yRoot].rank){
			ar[xRoot].parent = yRoot;
			merger(yRoot, xRoot);
		}
		else if(ar[xRoot].rank > ar[yRoot].rank){
			ar[yRoot].parent = xRoot;
			merger(xRoot, yRoot);
		}
		else{
			ar[yRoot].parent = xRoot;
			ar[xRoot].rank += 1;
			merger(xRoot, yRoot);
		}
	}
};

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

int main(){
	int t = inp(),n,k,d,x,y,xRoot,yRoot,ans;
	while(t--){
		n = inp(); k = inp();
		DisjointSet* ds = new DisjointSet(n);
		ans = 0;
		while(k--){
			d = inp(); x = inp(); y = inp(); x--, y--;
			if(x<0 || y<0 || x>=n || y>= n){
				ans++;
			}
			else if(d == 1){
				xRoot = ds->Find(x), yRoot = ds->Find(y);
				if((S[xRoot].count(yRoot) == 1) || (S[yRoot].count(xRoot) == 1)){
					ans++;
				}
				else{
					ds->Union(xRoot, yRoot);
				}
			}
			else{
				if(x == y)
					ans++;
				else{
					xRoot = ds->Find(x), yRoot = ds->Find(y);
					if(xRoot == yRoot)
						ans++;
					else{
						S[xRoot].insert(yRoot);
						S[yRoot].insert(xRoot);
					}
				}
			}
			printf("%d %d\n",k,ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}