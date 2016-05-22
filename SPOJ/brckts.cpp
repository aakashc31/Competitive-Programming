#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define LEFT(x) (2*x + 1)
#define RIGHT(x) (2*x + 2)
#define OPEN_BRACKET 1
#define CLOSED_BRACKET 2

struct node{
	int lOpen, rClose;
	node(int x, int y) : lOpen(x), rClose(y) {};
	node() { lOpen = 0, rClose = 0; };
	void merge(node& left, node& right){ //merges the left and right children
		lOpen = left.lOpen;
		rClose = right.rClose;
		int diff = left.rClose - right.lOpen;
		if(diff > 0) rClose += diff;
		else lOpen -= diff;
	}
};

const int maxn = 100000;
string st;
node ar[maxn];

void initiate(int index, int l, int r){
	if(l == r){
		if(st[l] == '(')
			ar[index] = node(0,1);
		else
			ar[index] = node(1,0);
		return;
	}
	int mid = (l+r)/2;
	initiate(LEFT(index), l, mid);
	initiate(RIGHT(index), mid+1, r);
	ar[index] = node(0,0);
	ar[index].merge(ar[LEFT(index)], ar[RIGHT(index)]);
}

void update(int index, int l, int r, int i, int changedTo){
	if(l == r){
		if(i == l){
			if(changedTo == OPEN_BRACKET)
				ar[index] = node(0,1);
			else
				ar[index] = node(1,0);
		}
		return;
	}
	int mid = (l+r)/2;
	if(i <= mid){
		update(LEFT(index), l, mid, i, changedTo);
	}
	else{
		update(RIGHT(index), mid+1, r, i, changedTo);
	}
	ar[index].merge(ar[LEFT(index)], ar[RIGHT(index)]);
}

bool query(){
	return (ar[0].lOpen == 0 && ar[0].rClose == 0);
}

int main(){
	ios::sync_with_stdio(false);
	int t = 10, n,m,ch,i,changedTo,curr;
	while(t--){
		cin >> n >> st;
		assert(st.length() == n);
		initiate(0, 0, n-1);
		cin >> m;
		cout << "Test " << (10 - t) << ":" << endl;
		while(m--){
			cin >> ch;
			if(ch == 0){
				if(query())
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
			else{
				i = ch-1;
				curr = (st[i] == ')') ? CLOSED_BRACKET : OPEN_BRACKET;
				changedTo = 3 - curr;
				st[i] = (changedTo == CLOSED_BRACKET) ? ')' : '(';
				update(0,0,n-1,i,changedTo);
			}
		}
	}
	return 0;
}