#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define LEFT(x) (2*x + 1)
#define RIGHT(x) (2*x + 2)

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int maxn = 500000;

pii tree[maxn];
int ar[maxn];

pii merge(pii& n1, pii& n2){
	if(n1==mp(-1,-1))
		return n2;
	else if(n2 == mp(-1,-1))
		return n1;
	if(ar[n1.first] > ar[n2.first]){
		if(n1.second == -1)
			return mp(n1.first, n2.first);
		else
			return mp(n1.first, (ar[n1.second] > ar[n2.first]) ? n1.second : n2.first);
	}
	else{
		if(n2.second == -1)
			return mp(n2.first, n1.first);
		else
			return mp(n2.first, (ar[n1.first] > ar[n2.second]) ? n1.first : n2.second);
	}
}

void initialize(int index, int l, int r){
	if(l == r){
		tree[index] = mp(l, -1);
		return;
	}
	int mid = (l+r)/2;
	initialize(LEFT(index), l, mid);
	initialize(RIGHT(index), mid+1, r);
	tree[index] = merge(tree[LEFT(index)], tree[RIGHT(index)]);
}

void update(int index, int l, int r, int i){
	if(l == r){
		return;
	}
	int mid = (l+r)/2;
	if(i <= mid)
		update(LEFT(index), l, mid, i);
	else
		update(RIGHT(index), mid+1, r, i);
	tree[index] = merge(tree[LEFT(index)], tree[RIGHT(index)]);
}

pii query(int index, int l, int r, int start, int end){
	if(end < l || start > r) //disjoint
		return mp(-1,-1);
	if(l>=start && r<=end) //current segment in subsegment of query range
		return tree[index];
	int mid = (l+r)/2;
	pii lRet = query(LEFT(index), l, mid, max(l, start), min(end, r));
	pii rRet = query(RIGHT(index), mid+1, r, max(l, start), min(end, r));
	return merge(lRet, rRet);
}

int main(){
	ios::sync_with_stdio(false);
	int n, q, x, y; char ch;
	cin >> n;
	for(int i=0; i<n; i++) cin >> ar[i];
	initialize(0, 0, n-1);
	cin >> q;
	while(q--){
		cin >> ch >> x >> y;
		if(ch == 'Q'){
			pii ans = query(0, 0, n-1, x-1, y-1);
			cout << ar[ans.first] + ar[ans.second] << endl;
		}
		else{
			ar[x-1] = y;
			update(0, 0, n-1, x-1);
		}
	}
	return 0;
}