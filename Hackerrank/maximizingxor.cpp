#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)
#define getStr(st) scanf("%s",st)

typedef long long int lli;

int xortemp(int a, int b)
{
	return ((!a)&b)|((!b)&a);
}

int main()
{
	int l,r;
	int max=0;
	getNum(l), getNum(r);
	for(int i=l;i<=r;i++)
	{
		for(int j=i+1;j<=r;j++)
		{
			int t = i^j;
			if(t>max)
				max=t;
		}
	}
	printf("%d\n",max);
	return 0;
}