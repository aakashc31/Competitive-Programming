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
		if(ar[xRoot].rank < ar[yRoot].rank)
			ar[xRoot].parent = yRoot;
		else if(ar[xRoot].rank > ar[yRoot].rank)
			ar[yRoot].parent = xRoot;
		else{
			ar[yRoot].parent = xRoot;
			ar[xRoot].rank += 1;
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

const int maxe = 1e6;
pii edges[maxe];
pii weight[maxe]; //(weight, index of edge)
int m,n;

int kruskal(){
	sort(weight, weight+m);
	int index = 0;
	int ans = 0, u, v;
	DisjointSet* ds = new DisjointSet(n);
	while(index < m){
		u = edges[weight[index].second].first;
		v = edges[weight[index].second].second;
		if(ds->Find(u) != ds->Find(v)){
			ans += weight[index].first;
			ds->Union(u,v);
		}
		index++;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t,x,w,p; string st;
	cin >> t;
	while(t--){
		cin >> n; m = 0;
		for(int i=0; i<n; i++){
			cin >> st >> p;
			while(p--){
				cin >> x >> w; x--;
				if(x < i)
					continue;
				edges[m] = mp(i,x);
				weight[m] = mp(w,m); m++;
			}
		}
		cout << kruskal() << endl;
	}
	return 0;
}