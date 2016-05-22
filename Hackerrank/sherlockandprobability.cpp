#include <stdio.h>
#include <cstring>
#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0;i<n;i++)
typedef long long int lli;
lli indices[100000]; //this will store the indices where 1s are present
char str[100000];

lli gcd(lli a, lli b)
{
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}

lli get_distinct_ij(int k, int l)
{
	lli s=0;
	f(i,l-1)
	{
		lli ith = indices[i];
		lli j=i+1;
		while(j<l && ((indices[j]-ith)<=k))
			s++,j++;
	}
	return 2*s;
}

int main()
{
	lli t,n,k;
	getNum(t);
	while(t--)
	{
		getNum(n), getNum(k);
		scanf("%s",str);
		lli l = strlen(str);
		lli num_ones = 0;
		
		// storing the indices of all 1's in the string
		f(i,l)
		{
			if(str[i]=='1')
			{
				num_ones++;
				indices[num_ones-1] = i;
			}
		}
		lli dist = get_distinct_ij(k,num_ones) + num_ones;
		lli poss = n*n;
		lli g = gcd(dist,poss);
		poss = poss / g;
		dist = dist / g;
		printf("%lld/%lld\n",dist,poss);
	}
	return 0;
}