#include <stdio.h>
#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)

int gcd(int a, int b)
{
	if(a<b)
		return gcd(b,a);
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int ar[100];
int main()
{
	int t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		f(i,n)
			getNum(ar[i]);
		if(n==1 && ar[0]==1)
		{
			printf("YES\n");
			continue;
		}
		else if(n==1)
		{
			printf("NO\n");
			continue;
		}
		int g = gcd(ar[0],ar[1]);
		for(int i=2;i<n;i++)
		{
			g = gcd(g,ar[i]);
			if(g==1)
				break;
		}
		if(g==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}