#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%d",&n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked
typedef long long int lli;

struct node
{
	node *left, *right;
}; //nl = left subtree size, nr right subtree ka size

// 0<=level<=31
// current level is level. And number to be inserted is num. 
void insert(node *v, int num, int level)
{
	// printf("At level %d for num = %d, made -> %d\n",level, num, v->num+1);
	if(level == -1)
	{
		return;
	}
	int k = num & (1<<level);
	if(k)
	{
		// printf("left\n");
		if(v->left == NULL)
		{
			node *temp = new node;
			temp->left = temp->right = NULL;
			v->left = temp;
		}
		insert(v->left, num, level-1);
	}
	else
	{
		// printf("right\n");
		if(v->right == NULL)
		{
			node *temp = new node;
			temp->left = temp->right = NULL;
			v->right = temp;
		}
		insert(v->right, num, level-1);
	}
}

inline void insert_iter(node* root, int num, int level){
	level = 31;
	node* v = root;
	while(level >= 0){
		int k = num & (1<<level);
		if(k){
			if(v->left == NULL){
				node *temp = new node;
				temp->left = temp->right = NULL;
				v->left = temp;
			}
			v = v->left;
		}
		else{
			if(v->right == NULL){
				node *temp = new node;
				temp->left = temp->right = NULL;
				v->right = temp;
			}
			v = v->right;
		}
		level--;
	}
}

// 
//return the maximum xor of this element with any of the previous element
inline int query(node* n, int num){
	int i = 31;
	int ans = 0;
	while(i>=0){
		int bit = num & (1<<i);
		if(bit){
			if(n->right != NULL){ //we want 0
				// cout << i << " is on 1" << endl;
				n = n->right;
				ans |= (1<<i);
			}
			else
				n = n->left;
		}
		else{
			if(n->left != NULL){
				// cout << i << " is on 2" << endl;
				ans |= (1<<i);
				n = n->left;
			}
			else
				n = n->right;
		}
		i--;
	}
	return ans;
}


void computePrefixXor(int* ar, int* pref, int size){
	pref[0] = ar[0];
	for(int i=1; i<size; i++)
		pref[i] = pref[i-1]^ar[i];
}

inline void computePrefixAndSuffixXor(int* ar, int* pref, int* suff, int size){
	pref[0] = ar[0];
	suff[0] = ar[size-1];
	for(int i=1; i<size; i++){
		pref[i] = pref[i-1]^ar[i];
		suff[i] = suff[i-1]^ar[size-1-i];
	}

}
 
inline void computeMaxXorForEachElement(int* ar,int* br, int size, int* ret, int* bret){

	node* root = new node;
	root->left = root->right = NULL;
	insert_iter(root, 0, 31);

	node* broot = new node;
	broot->left = broot->right = NULL;
	insert_iter(broot, 0, 31);

	// cout << "ar ";
	// f(i,size) cout << ar[i] << " ";
	// cout << endl;

	for(int i=0; i<size; i++){
		ret[i] = query(root, ar[i]);
		bret[i] = query(broot, br[i]);
		// cout << "ar[" << i << "] = " << ar[i] << ", query = " << ret[i] << endl;
		if(i>0) ret[i] = max(ret[i], ret[i-1]);
		if(i>0) bret[i] = max(bret[i], bret[i-1]);
		insert_iter(root, ar[i], 31);
		insert_iter(broot, br[i],31);
	}
}

int ar[400005];

int prefAr[400005]; //suffix array of xor
int suffAr[400005]; //prefix array of xor

int retAr[400005];

int retRevAr[400005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", ar+i);
	}
	
	computePrefixAndSuffixXor(ar, prefAr, suffAr,n); //suffAr[n-1-i] = ar[i]^ar[i+1]^....^ar[n-1]

	computeMaxXorForEachElement(prefAr,suffAr, n, retAr,retRevAr);
	// computeMaxXorForEachElement(suffAr, n, retRevAr);

	int ans = retAr[0] + retRevAr[n-2];

	for(int i=1; i<n-1; i++){
		ans = max(ans, retAr[i] + retRevAr[n-i-2]);
	}

	printf("%d\n", ans);
	return 0;

}
