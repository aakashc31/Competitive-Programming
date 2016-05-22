// segment tree didn't work, now using segment tree with lazy propagation
#include <iostream>
#include <stdio.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()
#define outch putchar//_unlocked
#define getNum(n) scanf("%d",&n)
int inputInteger()
{
	char ch = inpch;
	int r=0;
	while(ch!='\n' && ch!=' ')
	{
		r = r*10 + ch-'0';
		ch = inpch;
	}
	return r;
}



struct node
{
	int left,right,numHeads;
	node* l;
	node* r;
	bool lazy;
};

void initiate(node* n, int l, int r)
{
	// cout << l <<" "<< r << "\n";
	n -> left = l;
	n -> right = r;
	n -> numHeads = 0;
	n -> lazy = false;

	if(l<r)
	{
		node* lft = new node;
		n->l = lft;
		initiate(lft,l,(l+r)/2);
		node* rt = new node;
		n->r = rt;
		initiate(rt, (l+r)/2+1,r);
	}
	else
	{
		n->l = n->r = NULL;
	}
}

void flipthecoins(node* v, int a, int b)
{
	if(v==NULL)
		return;
	if(v->lazy)
	{
		v->numHeads = (v->right - v->left +1) - v->numHeads; //performing the old ops
		if(v->left < v->right)
		{
			v->l->lazy = !(v->l->lazy);
			v->r->lazy = !(v->r->lazy);
		}
		v->lazy = false;
	}
	if(v->right < a || v->left > b) //not in range
		return;
	else if(v->right==v->left) //leaf node
	{
		v->numHeads = (v->numHeads==0)?1:0;
		// cout << v->right -1<<" flipped to "<<v->numHeads <<endl;
	}

	else if(v->left>=a && v->right<=b)
	{
		v->numHeads = (v->right - v->left + 1) - (v->numHeads);
		v->l->lazy = !(v->l->lazy);
		v->r->lazy = !(v->r->lazy);
	}
	else
	{
		flipthecoins(v->l,a,b);
		flipthecoins(v->r,a,b);
		v->numHeads = v->l->numHeads + v->r->numHeads;
	}
}

int numberofheads(node* v, int a, int b)
{
	if(v==NULL)
		return 0;
	if(v->lazy)
	{
		v->numHeads = (v->right - v->left + 1) -(v->numHeads);
		if(v->right > v->left)
		{
			v->l->lazy = !(v->l->lazy);
			v->r->lazy = !(v->r->lazy);
		}
		v->lazy = false;
	}
	if(v->right < a || v->left > b)
		return 0;
	else if(v->left>=a && v->right<=b)
		return v->numHeads;
	else
		return numberofheads(v->l,a,b)+numberofheads(v->r,a,b);
}

int main()
{
	int n=inputInteger(),q=inputInteger();
	// int n,q;
	// scanf("%d",&n);
	// scanf("%d",&q);
	node* root = new node;
	initiate(root,1,n);
	while(q--)
	{
		int ch = inputInteger(),a=inputInteger(),b=inputInteger();
		// int ch,a,b;
		// scanf("%d",&ch);
		// scanf("%d",&a);
		// scanf("%d",&b);
		// cout << ch << endl;
		if(ch==0)
		{
			//flip the coins
			flipthecoins(root,a+1,b+1);
		}
		else
		{
			// return number of heads
			printf("%d\n",numberofheads(root,a+1,b+1));
		}
	}
	return 0;
}