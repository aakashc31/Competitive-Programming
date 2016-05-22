// given an array, find the subarray whose XOR is maximum
// F[L..R] = a[L]^a[L+1]^...^a[R]
// F[L..R] = F[1..L-1] ^ F[1..R]
// Hence if we have prefix xor's for all indices, we need to find those two indices whose xor is maximum

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

struct node
{
	int num;
	node *left, *right;
}; 

// 0<=level<=31
void insert(node *v, int num, int level)
{
	v->num++;
	if(level == -1)
	{
		return;
	}
	int k = num & (1<<level);
	if(k)
	{
		if(v->left == NULL)
		{
			node *temp = new node;
			temp->left = temp->right = NULL;
			temp->num = 0;
			v->left = temp;
		}
		insert(v->left, num, level-1);
	}
	else
	{
		if(v->right == NULL)
		{
			node *temp = new node;
			temp->left = temp->right = NULL;
			temp->num = 0;
			v->right = temp;
		}
		insert(v->right, num, level-1);
	}
}

int query(node* v, int num, int level, int ans)
{
	if(level==-1 || v==NULL)
		return ans;
	int k = num & (1<<level);
	if(k)
	{
		if(v->right != NULL)
		{
			query(v->right, num, level-1, (ans<<1));	
		}
		else
		{
			query(v->left, num, level-1, (ans<<1)+1);
		}
	}

	else
	{
		if(v->left != NULL)
		{
			query(v->left, num, level-1, (ans<<1)+1);
		}
		else
		{
			query(v->right, num, level-1, (ans<<1));
		}
	}
}

int find_max_xor_pair(int* ar, int len)
{
	node* root = new node;
	root->left = root->right = NULL;
	int m = 0, temp;
	f(i,len)
	{
		insert(root, ar[i],31);
		temp = query(root, ar[i], 31, 0);
		temp = temp^ar[i];
		if(temp>m)
			m = temp;
	}
	// printf("Smart ans: = %d\n",m);
	return m;
}

void find_max_xor_subsection(int* ar, int len)
{
	int* aux = new int[len+1];
	aux[0] = 0;
	fab(i,1,len)
	{
		aux[i] = aux[i-1]^ar[i-1];
	}
	printf("%d\n",find_max_xor_pair(aux,len+1));
}

void brute_force(int* ar, int len)
{
	int ans = 0;
	f(i,len)
	{
		fab(j,i+1,len-1)
		{
			int temp = 0;
			fab(k,i,j)
			{
				temp = temp^ar[k];
			}
			if(temp > ans)
				ans = temp;
		}
	}
	printf("Brute ans = %d\n",ans);
}
int *ar;
int main()
{
	ar = new int[100000];
	int t,n;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n) g(ar[i]);
		find_max_xor_subsection(ar,n);
	}
	return 0;
}