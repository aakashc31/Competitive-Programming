// segment tree
#include <bits/stdc++.h>
using namespace std;

const int maxn = 80000;
int tree[maxn];

typedef vector<int> vi;
#define left(x) 	(2*x+1)
#define right(x)	(2*x+2)

void build(int index, int l, int r){
	if(l==r){
		tree[index] = 1;
		return;
	}
	int mid = (l+r)/2;
	build(left(index), l, mid);
	build(right(index), mid+1, r);
	tree[index] = tree[left(index)] + tree[right(index)];
}

void update(int index, int l, int r, int i){
	if(i < l || i > r)
		return;
	if(l==r){
		tree[index]--;
		return;
	}
	int mid = (l+r)/2;
	update(left(index), l, mid, i);
	update(right(index), mid+1, r, i);
	tree[index] = tree[left(index)] + tree[right(index)];
}

int query(int index, int l, int r, int il, int ir){
	if(ir < l || il > r)
		return 0;
	if(l>=il && r<=ir)
		return tree[index];
	int mid = (l+r)/2, iln = max(l,il), irn = min(r,ir);
	int ret = query(left(index), l, mid, iln, irn) + query(right(index), mid+1, r, iln, irn);
	return ret;
}

int ithZero(int index, int l, int r, int j){
	if(l==r)
		return l;
	int lz = tree[left(index)], rz = tree[right(index)], mid = (l+r)/2;
	if(j<=lz)
		return ithZero(left(index), l, mid, j);
	else
		return ithZero(right(index),mid+1, r, j-lz);
}

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(n==1){
			cout << 1 << endl; continue;
		}
		build(0, 0, n-1);
		vi ans(n,0);
		update(0,0,n-1,1);
		ans[1] = 1;
		int curr = 1;
		for(int i=2; i<=n; i++){
			int lz = query(0,0,n-1,0,curr-1), rz = query(0,0,n-1,curr,n-1);
			int z = (i%(lz+rz)) + 1;
			if(z <= rz){
				curr = ithZero(0,0,n-1, lz+z);
			}
			else{
				curr=ithZero(0,0,n-1,z-rz);
			}
			update(0,0,n-1,curr);
			ans[curr] = i;
		}
		for(int i=0; i<n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}