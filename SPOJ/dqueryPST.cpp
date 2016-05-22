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


struct node{
	int cnt;
	node *left, *right;
	node(int cnt, node *left, node *right) : cnt(cnt), left(left), right(right) {};
	node* insert(int l, int r, int w);
};

node* null = new node(0, NULL, NULL);

node* node::insert(int l, int r, int w){
	if(l <= w && w < r){
		if(l+1 == r)
			return new node(this->cnt+1, NULL, NULL);
		int m = (l+r)>>1;
		return new node(this->cnt+1, this->left->insert(l,m,w), this->right->insert(m,r,w));
	}
	return this;
}

int query(node* a, node *b, int l, int r, int k){ //returns freq till k
	if(k <= l)
		return 0;
	if(k >= r)
		return (a->cnt - b->cnt);
	int m = (l+r)>>1;
	return query(a->left, b->left, l, m, k) + query(a->right, b->right, m, r, k);
}

const int N = 30010; const int maxval = 1e6+10;
int a[N]; int prevIndex[N]; //prevIndex[i] stores the rightmost occurence to left of i of a[i]
node* root[N];
int currIndex[maxval]; //bucket
int main(){
	int n = inp();
	for(int i=1; i<=n; i++){
		a[i] = inp();
		prevIndex[i-1] = currIndex[a[i]];
		currIndex[a[i]] = i;
	}
	null->left = null->right = null;
	for(int i=0; i<n; i++)
		root[i] = (i==0 ? null : root[i-1])->insert(0, n+1, prevIndex[i]);
	int d = inp();
	while(d--){
		int u,v; u = inp(); v = inp();
		printf("%d\n", query(root[v-1], ((u==1)?null:root[u-2]), 0, n+1, u));
	}
	return 0;
}

