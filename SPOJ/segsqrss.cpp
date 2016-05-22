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

struct node{
	int lazy1, lazy2; bool isLazy;
	int sumSquare, sum;
} tree[maxn];

void unLazify(int index, int l, int r){
	if(tree[index].isLazy){
		int x = tree[index].lazy2;
		tree[LEFT(index)].isLazy = true; tree[LEFT(index)].lazy2 = x;
		tree[RIGHT(index)].isLazy = true; tree[RIGHT(index)].lazy2 = x;
		tree[index] = node(0,0,false, (r-l+1)*x*x, (r-l+1)*x);
	}
	else{
		int x = tree[index].lazy1;
		int s = tree[index].sum;
		int sumSquare = tree[index].sumSquare + (r-l+1)*x*x + 2*s*x;
		tree[index] = node(0,0,false, sumSquare,s+(r-l+1)*x)
	}
}