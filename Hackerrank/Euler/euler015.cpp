#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

typedef long long int lli;
const int mod = 1000000007;

lli ar[500][500];
int main()
{
	int t,n,m;
	getNum(t);
	while(t--)
	{
		lli s = 0;
		getNum(n), getNum(m);
		n++,m++;
		ar[0][0] = 1;
		f(i,n)
		{
			f(j,m)
			{
				if(j==0 && i!=0)
				{
					ar[i][j] = 1;
				}
				else if(i==0 && j!=0)
				{
					ar[i][j] = 1; 
				}
				else if(i>=1)
				{
					ar[i][j] = (ar[i-1][j] + ar[i][j-1])%mod;
				}
			}
		}
		printf("%lld\n",ar[n-1][m-1]);
	}
	return 0;
}