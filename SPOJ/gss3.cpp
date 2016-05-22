#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;




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
#define inf 1000000000

#define Left(x) (2*x+1)
#define Right(x) (2*x+2)

struct node
{
	int maxSubarray;
	int prefix;
	int suffix;
	int sum;
};

node tree[500000];

int ar[50000];

node merge(node& l, node& r){
	node ret;
	ret.sum = l.sum + r.sum;
	ret.prefix = max(l.prefix, l.sum + r.prefix);
	ret.suffix = max(r.suffix, r.sum + l.suffix);
	ret.maxSubarray = max(l.suffix+r.prefix,max(l.maxSubarray, r.maxSubarray));
	return ret;
}

void initiate(int index, int left, int right){
	if(left > right)
		return;
	if(left == right)
		tree[index] = (node){ar[left], ar[left], ar[left], ar[left]}; //what if ar[left] is negative
	else{
		int mid = (left+right)/2;
		initiate(Left(index), left, mid);
		initiate(Right(index), mid+1, right);
		tree[index] = merge(tree[Left(index)], tree[Right(index)]);
	}
}

node query(int index, int left, int right, int ql, int qr){
	if(right < ql || qr < left)
		return ((node){-inf, -inf, -inf, -inf});
	if(left >= ql && right <= qr)
		return tree[index];
	else{
		int mid = (left+right)/2;
		int lefLimit = max(left, ql);
		int rightLimit = min(right, qr);
		if(rightLimit <= mid || lefLimit > mid){
			if(rightLimit <= mid)
				return query(Left(index), left, mid, ql, qr);
			else
				return query(Right(index), mid+1, right, ql, qr);
		}
		else{
			node leftQuery = query(Left(index), left, mid, ql, qr);
			node rightQuery = query(Right(index), mid+1, right, ql, qr);
			node ret = merge(leftQuery, rightQuery);
			return ret;
		}

	}
}

void update(int index, int left, int right, int updt, int val){
	if(updt > right || updt < left)
		return;
	if(left == right){
		tree[index] = (node){val,val,val,val};
	}
	else{
		int mid = (left+right)/2;
		if(updt <= mid)
			update(2*index+1, left, mid, updt, val);
		else
			update(2*index+2, mid+1, right, updt, val);
		tree[index] = merge(tree[Left(index)], tree[Right(index)]);
	}
}

int main(){
	int n,m,ch,x,y;
	n = inp();
	for(int i=0; i<n; i++)
		ar[i] = inp();
	initiate(0, 0, n-1);

	m = inp();
	while(m--){
		ch = inp();
		x = inp();
		y = inp();
		if(ch == 0){
			update(0,0,n-1,x-1,y);
		}
		else{
			printf("%d\n",query(0,0,n-1,x-1,y-1).maxSubarray);
		}
	}
	return 0;
}