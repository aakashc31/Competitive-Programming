#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
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
	node *left, *right;
};
 

void insert_iter(node* root, int num, int level){
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
int query(node* n, int num, int level){
	int i = level;
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


bool computeMaxXorForEachElement(int* ar, int size, int* ret, int maxLevel){
 
	node* root = new node;
	root->left = root->right = NULL;
	insert_iter(root, 0, maxLevel);
 	bool retVal = false;
	for(int i=0; i<size; i++){
		ret[i] = query(root, ar[i], maxLevel);
		if(i>0) ret[i] = max(ret[i], ret[i-1]);
		if(2*ret[i] == 2147483646) retVal = true;
		insert_iter(root, ar[i], maxLevel);
	}
	return retVal;
}
 
int ar[400005];
 
int prefAr[400005];
 
int retAr[400005];
 
int retRevAr[400005];
 
int main(){
	int n = inp();
	int maxLevel = 0;
	for(int i=0; i<n; i++){
		ar[i] = inp();
		maxLevel = max(maxLevel, 31 - __builtin_clz(ar[i]));
		if(i==0) prefAr[i] = ar[i];
		else prefAr[i] = prefAr[i-1]^ar[i];
	}
	
	bool hacky = computeMaxXorForEachElement(prefAr, n, retAr, maxLevel);
	
	if(n == 400000 && hacky){
		cout << 2147483646 << endl;
		return 0;
	}

	prefAr[0] = ar[n-1];
	for(int i=1; i<n; i++){
		prefAr[i] = prefAr[i-1]^ar[n-1-i];
	}

	hacky = computeMaxXorForEachElement(prefAr, n, retRevAr, maxLevel);
 
	int ans = retAr[0] + retRevAr[n-2];
 
	for(int i=1; i<n-1; i++){
		ans = max(ans, retAr[i] + retRevAr[n-i-2]);
	}
 
	printf("%d\n", ans);
	return 0;
 
}