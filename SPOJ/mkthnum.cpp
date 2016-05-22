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


//persistent segment tree
struct node{
	int count;
	node *left, *right;
	node(int count, node* left, node* right) : count(count), left(left), right(right) {};
	node* insert(int l, int r, int w);
};

node* null = new node(0, NULL, NULL);

node* node::insert(int l, int r, int w){
	if(l <= w && w < r){
		if(l+1 == r){
			return new node(this->count+1, NULL, NULL);
		}
		int m = (l+r)>>1;
		return new node(this->count+1, this->left->insert(l,m,w), this->right->insert(m,r,w));
	}
	return this;
}

int query(node* a, node* b, int l, int r, int k){
	if(l+1 == r)
		return l;
	int m = (l+r)>>1;
	int count = a->left->count - b->left->count;
	if(count >= k)
		return query(a->left, b->left, l, m, k);
	return query(a->right, b->right, m, r, k-count);
}

const int N = 1e5+10;
int a[N], RM[N];
node* root[N];
int main(){
	int n,m,u,v,k,ans;
	n = inp(); m = inp();
	map<int,int> M;
	for(int i=0; i<n; i++){
		a[i] = inp(); M[a[i]];
	}
	int maxi = 0;
	for(map<int,int>::iterator it = M.begin(); it != M.end(); it++){
		M[it->first] = maxi;
		RM[maxi] = it->first;
		maxi++;
	}
	null->left = null->right = null;
	for(int i=0; i<n; i++){
		root[i] = (i==0 ? null : root[i-1])->insert(0, maxi, M[a[i]]);
	}
	while(m--){
		u = inp()-1; v = inp()-1; k = inp();
		ans = query(root[v], (u==0?null:root[u-1]), 0, maxi, k);
		printf("%d\n", RM[ans]);
	}
	return 0;
}
