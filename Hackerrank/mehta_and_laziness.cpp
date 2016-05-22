#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

bool isEvenSqaure(int n)
{
	if(n&1)
		return false;
	int q = sqrt(n);
	return (q*q == n);
}

int main()
{
	int t,n;
	g(t);
	while(t--)
	{
		g(n);
		int p = 0, s=0;
		for(int i=1; i*i<=n; i++)
		{
			if(n%i==0)
			{
				if(i*i==n)
				{
					s++; //num div
					if(isEvenSqaure(i))
						p++;
				}
				else
				{
					s+=2;
					if(i==1) s--;
					if(isEvenSqaure(i))
						p++;
					if(isEvenSqaure(n/i) && i!=1)
						p++;
				}
			}
		}
		int q = __gcd(p,s);
		if(p==0)
			printf("0\n");
		else
			printf("%d/%d\n",p/q,s/q);
	}
	return 0;
}