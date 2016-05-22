#include <stdio.h>
#include <algorithm>

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int n;
		getNum(n);
		int s=1;
		int i;
		for(i=2; i*i <= n;i++)
		{
			if(n%i==0)
				s+=(i + n/i);
		}
		i--;
		if(i*i==n)
			s-=i;
		printf("%d\n",s);
	}
	return 0;
}