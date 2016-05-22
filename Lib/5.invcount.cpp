#include <stdio.h>
#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)

typedef long long int lli;
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
int ar[200010];
int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int n;
		scanf("\n%d",&n);
		f(i,n)
			getNum(ar[i]);
		printf("%lld\n",count_inversions(ar,0,n-1));
	}
	return 0;
}