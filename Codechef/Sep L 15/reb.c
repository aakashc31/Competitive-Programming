#include <stdio.h>
#include <stdlib.h>
#define g(n) scanf("%d",&n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked
typedef long long int lli;

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

struct node
{
	struct node *left, *right;
}; //nl = left subtree size, nr right subtree ka size

typedef struct node node;
 
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
			node *temp = (node*)malloc(8);
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
			node *temp = (node*)malloc(8);
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
				node *temp = (node*)malloc(8);
				temp->left = temp->right = NULL;
				v->left = temp;
			}
			v = v->left;
		}
		else{
			if(v->right == NULL){
				node *temp = (node*)malloc(8);
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
	int i=1;
	for(i=1; i<size; i++)
		pref[i] = pref[i-1]^ar[i];
}

inline void computeSuffixXor(int* ar, int* suff, int size){
	suff[0] = ar[size-1];
	int i=1;
	for(i=1; i<size; i++){
		suff[i] = suff[i-1]^ar[size-1-i];
	}
}
 
inline void computePrefixAndSuffixXor(int* ar, int* pref, int* suff, int size){
	pref[0] = ar[0];
	suff[0] = ar[size-1];
	int i=1;
	for(i=1; i<size; i++){
		pref[i] = pref[i-1]^ar[i];
		suff[i] = suff[i-1]^ar[size-1-i];
	}
 
}
 
inline void computeMaxXorForEachElement(int* ar, int size, int* ret){
 
	node *root = (node*)malloc(8);
	root->left = root->right = NULL;
	insert_iter(root, 0, 31);
 
	// cout << "ar ";
	// f(i,size) cout << ar[i] << " ";
	// cout << endl;
 	int i=0;
	for(i=0; i<size; i++){
		ret[i] = query(root, ar[i]);
		// cout << "ar[" << i << "] = " << ar[i] << ", query = " << ret[i] << endl;
		if(i>0) ret[i] = max(ret[i], ret[i-1]);
		insert_iter(root, ar[i], 31);
	}
}
 
int ar[400005];
 
int prefAr[400005]; //suffix array of xor
int suffAr[400005]; //prefix array of xor
 
int retAr[400005];
 
int retRevAr[400005];

inline int max(int a, int b){
	return (a>b) ? a:b;
}

int main(){
	int n = inp();
	int i=0;
	for(i=0; i<n; i++){
		ar[i] = inp();
		if(i==0) prefAr[i] = ar[i];
		else prefAr[i] = prefAr[i-1]^ar[i];
	}
	
	// computePrefixAndSuffixXor(ar, prefAr, suffAr,n); //suffAr[n-1-i] = ar[i]^ar[i+1]^....^ar[n-1]
 	// computePrefixXor(ar, prefAr, n);
 	computeSuffixXor(ar, suffAr, n);

	computeMaxXorForEachElement(prefAr, n, retAr);
	computeMaxXorForEachElement(suffAr, n, retRevAr);
 
	int ans = retAr[0] + retRevAr[n-2];
 
	for(i=1; i<n-1; i++){
		ans = max(ans, retAr[i] + retRevAr[n-i-2]);
	}
 
	printf("%d\n", ans);
	return 0;
 
}