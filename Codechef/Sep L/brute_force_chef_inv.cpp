#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
int ar[200000];
int br[200000];
int array_size;

lli count_inversions(int ar[], int left, int right)
{
	// base case
	if(left==right)
		return 0;
	int mid = (left+right)/2;

	lli l = count_inversions(ar,left, mid);
	lli r = count_inversions(ar,mid+1, right);
	lli s = 0;
	int i=left, j=mid+1;
	int new_ar[right-left+1];
	int n_ind = 0;
	while(i<=mid || j<=right)
	{
		if(i>mid)
		{
			while(j<=right)
			{
				new_ar[n_ind] = ar[j];
				j++;
				n_ind++;
			}
			break;
		}

		if(j>right)
		{
			while(i<=mid)
			{
				new_ar[n_ind] = ar[i];
				i++;
				n_ind++;
			}
			break;
		}

		if(ar[i] <= ar[j])
		{
			new_ar[n_ind++] = ar[i++];
		}
		else
		{
			new_ar[n_ind++] = ar[j];
			s+=(mid-i+1);
			j++;
		}
	}

	f(i,right-left+1)
		ar[left+i] = new_ar[i];
	s+=(l+r);
	return s;
}

int main()
{
	int n,m,i,j,it,jt;
	g(n),g(m);
	array_size = n;
	f(i,n) g(br[i]);
	// create_segment_tree(ar,0,n-1,1);
	// f(i,n) printf("%d ", ar[i]); printf("\n");
	// lli num_inv = count_inversions(br,0,n-1);
	// f(i,n) printf("%d ", ar[i]); printf("\n");
	while(m--)
	{
		g(it),g(jt);
		it--,jt--;
		i = min(it,jt);
		j = max(it,jt);
		f(k,n) ar[k] = br[k];
		swap(ar[i],ar[j]);
		printf("%lld\n",count_inversions(ar,0,n-1));
		// swap(ar[i],ar[j]);
	}
	return 0;
}

