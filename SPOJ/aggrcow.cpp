#include <bits/stdc++.h>
using namespace std;
#define fr(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)

int ar[100000];

// returns true if c cows can be places int ar such that least distance betweeen any of them is atleast dist
bool f(int c, int dist, int n)
{
	int placed = 1;
	int prev = ar[0];
	for(int i=1; i<n; i++)
	{
		if(ar[i] - prev >= dist)
		{
			placed++;
			prev = ar[i];
			if(placed == c)
				return true;
		}
	}
	return false;
}

int max_min_dist(int i, int j, int c, int n)
{
	if(i>=j)
		return i-1;
	int mid = (i+j)/2;
	bool i1 = f(c,mid,n);
	if(i1)
		return max_min_dist(mid+1, j , c, n);
	else
		return max_min_dist(i, mid, c, n);
}

int main()
{
	int t,n,c;
	g(t);
	while(t--)
	{
		g(n),g(c);
		fr(i,n) g(ar[i]);
		sort(ar,ar+n);
		printf("%d\n",max_min_dist(0,ar[n-1],c,n));
	}
	return 0;
}