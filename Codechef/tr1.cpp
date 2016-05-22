#include <iostream>
#include <stdio.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)

class node 
{
public:
	int size = 0;
	int left = 0;
	int right = 0;
};

int computeSize(node tree[], int i)
{
	if(tree[i].size != 0)
		return tree[i].size;
	if(i==0)
		return 0;
	else if(tree[i].left==0 && tree[i].right ==0)
	{
		tree[i].size = 1;
		return 1;
	}
	else
	{
		int k = computeSize(tree,tree[i].left);
		int l = computeSize(tree,tree[i].right);
		tree[i].size = k+l+1;
		return (k+l+1);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-- > 0)
	{
		int n; //number of nodes
		scanf("%d",&n);
		node tree[n+1];
		f(i,n-1)
		{
			int a,b;
			scanf("%d",&a);
			scanf("%d",&b);
			if(tree[a].left == 0)
			{
				tree[a].left = b;
			}
			else
			{
				tree[a].right = b;
			}
		}
		tree[0].size = 0;
		computeSize(tree,1);
		int modulo = 1000000007;
		long long int sum = 0;
		// for(int i=1; i<=n; i++)
		// {
		// 	cout << i << " -> " << tree[i].size << endl;
		// }
		for(int i=1; i<=n; i++)
		{
			int temp = 2*tree[i].size + 2*tree[tree[i].left].size*tree[tree[i].right].size - 1;
			// cout << "imp = " << temp << endl;
			long long int imp = temp*i;
			sum = (sum+ imp%modulo)%modulo;
		}
		printf("%d\n", sum);

	}	
	return 0;
}