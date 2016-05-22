#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

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

struct node{
	ll sum;
	ll lazy;
};

node tree[500009];
ll ar[100000];

ll initiate(int index, int left, int right){
	if(left == right){
		tree[index] = {ar[left], 0};
		return ar[left];
	}
	else{
		int mid = (left + right)/2;
		ll curr = initiate(2*index + 1, left, mid) + initiate(2*index + 2, mid+1, right);
		tree[index] = {curr, 0};
		return curr;
	}
}

void update(int index, int left, int right, int ql, int qr, ll val){
	ll currLazy = tree[index].lazy;
	if(currLazy != 0){
		tree[index].lazy = 0;
		tree[index].sum += ((right-left+1)*currLazy);
		if(left < right){
			tree[2*index+1].lazy += currLazy;
			tree[2*index+2].lazy += currLazy;
		}
	}
	if(qr < left || right < ql){ //disjoint
		return;
	}
	if(left >= ql && right <= qr){ //subset
		tree[index].sum += ((right-left+1)*val);
		if(right > left){
			tree[2*index + 1].lazy += val;
			tree[2*index + 2].lazy += val;
		}
		return;
	}
	else{
		int mid = (left + right)/2;
		update(2*index+1, left, mid, ql, qr, val);
		update(2*index+2, mid+1, right, ql, qr, val);
		tree[index].sum = tree[2*index+1].sum + tree[2*index+2].sum;
		return;
	}
}

ll query(int index, int left, int right, int ql, int qr){
	ll currLazy = tree[index].lazy;
	if(currLazy != 0){ 
		tree[index].lazy = 0;
		tree[index].sum += ((right-left+1)*currLazy);
		if(left < right){
			tree[2*index+1].lazy += currLazy;
			tree[2*index+2].lazy += currLazy;
		}
	}
	if(qr < left || right < ql){ //disjoint
		return 0;
	}	
	if(left >= ql && right <= qr){ //subset
		return tree[index].sum;
	}
	else{
		int mid = (left + right)/2;
		ll ret = query(2*index + 1, left, mid, ql, qr) + query(2*index + 2, mid + 1, right, ql, qr);
		return ret;
	}
}

int main(){
	int t,n,c,p,q,v,ch;
	t = inp();
	while(t--){
		n = inp();
		memset(ar, 0, 4*n);
		c = inp();
		initiate(0, 0, n-1);
		while(c--){
			ch = inp();
			p = inp(); q = inp();
			p--,q--;
			if(ch == 0){
				v = inp();
				update(0, 0, n-1, p, q, v);
			}
			else{
				printf("%lld\n", query(0,0,n-1,p,q));
			}
		}
	}
	return 0;
}