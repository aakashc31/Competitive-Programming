#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define get(n) scanf("%d",&n)
typedef long long int lli;
int ar[100001];
int ans[10000][2];
int q;
int main()
{
	q=0;
	int n;
	get(n);
	f(i,n) get(ar[i+1]);
	//input over
	int swaps_rem = 2*n;
	lli rsum = 0, lsum = 0;
	f(i,n/2)
	{
		lsum+=ar[i+1];
		rsum+=ar[i+1+n/2];
	}
	lli init = abs(rsum-lsum);
	while(swaps_rem > 0)
	{
		if(rsum>lsum)
		{
			int maxx = 0,r=n/2+1;
			for(int i=n/2+1;i<=n;i++)
			{
				if(ar[i]-ar[n/2] > maxx)
				{
					maxx = ar[i]-ar[n/2];
					r = i;
				}
			}
			int temp = ar[r],l;
			if(swaps_rem >= r)
				l = 1;
			else
				break;
			swaps_rem -= (r-l+1);
			for(int i=l;i<=r;i++)
			{
				int t = ar[i];
				ar[i]=temp;
				temp = t;
			}
			// printf("%d %d\n",l,r);
			ans[q][0] = l;
			ans[q][1] = r;
			q++; 
			rsum = rsum - ar[r] + ar[n/2];
			lsum = lsum - ar[n/2] + ar[r];
		}
		else
		{
			int maxx = 0,r=n/2+1;
			for(int i=n/2+1;i<=n;i++)
			{
				if(ar[n/2]-ar[i] > maxx)
				{
					maxx = ar[n/2]-ar[i];
					r = i;
				}
			}
			int temp = ar[r],l;
			if(swaps_rem >= r)
				l = 1;
			else
				break;
			swaps_rem -= (r-l+1);
			for(int i=l;i<=r;i++)
			{
				int t = ar[i];
				ar[i]=temp;
				temp = t;
			}
			ans[q][0] = l;
			ans[q][1] = r;
			q++;
			rsum = rsum - ar[r] + ar[n/2];
			lsum = lsum - ar[n/2] + ar[r];
		}
	}
	printf("%d\n",q);
	f(i,q)
	{
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}