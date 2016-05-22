#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long int lli;

#define f(i,n) for(lli i=0; i<n; i++)
#define g(n) scanf("%lld",&n)
lli ar[100000];
pii diff[100000];

bool comparator(const pii& a, const pii& b)
{
	return a.first < b.first;
}

// makes the difference of ar[i] & ar[i+1] the c.d. of the A.P
bool isBeautiful(lli i, lli k, lli n)
{
	lli cd = ar[i+1] - ar[i];
	lli f = ar[i] - cd*i;
	lli num_changes = 0;
	f(j,n)
	{
		if(ar[j] != (f+cd*j))
			num_changes++;
	}
	// printf("%d %d \n",i,num_changes);
	return (num_changes<=k);
}

int main()
{
	lli n,k;
	g(n), g(k);
	f(i,n) g(ar[i]);
	f(i,n-1)
	{
		lli cd = ar[i+1]-ar[i];
		lli f = ar[i] - i*cd;
		// printf("%d \n",f);
		diff[i] = make_pair(f,cd); 
	}
	sort(diff, diff+n);
	lli i;
	for(i=0;i<n-1;i++)
	{
		if(i==0)
		{
			if(isBeautiful(0,k,n))
				break;
		}
		else
		{
			if((diff[i].first != diff[i-1].first) || (diff[i].second != diff[i-1].second))
			{
				if(isBeautiful(i,k,n))
					break;
			}
		}
	}
	lli f = diff[i].first;
	lli cd = diff[i].second;
	f(i,n)
		printf("%lld ", (f + i*cd));
	printf("\n");
	return 0;
}