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

struct node{
	bool leaf;
	node* left; node* right;
	node(bool x, node* l, node* r) : leaf(x), left(l), right(r) {};
	node() : leaf(false), left(NULL), right(NULL) {};
};

int maxDepth = 0;
node* getTree(string& st, int& i, int depth){
	maxDepth = max(maxDepth, depth);
	if(st[i] == 'l'){
		i++;
		return (new node(true, NULL, NULL));
	}
	node* n = new node(false, NULL,NULL);
	i++;
	n->left = getTree(st, i, depth+1);
	n->right = getTree(st, i, depth+1);
	return n;
}

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t; string st;
	while(t--){
		cin >> st;
		int l = 0; maxDepth = 0;
		getTree(st, l, 0);
		cout << maxDepth << endl;
	}
	return 0;
}