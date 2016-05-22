#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
#define getNum(n) scanf("%d",&n)

int inputInteger()
{
	char ch = inpch;
	register int r=0;
	while(ch!='\n' && ch!=' ')
	{
		r = (r<<1) + (r<<3) + ch-'0';
		ch = inpch;
	}
	return r;
}
int main()
{
	int t = inputInteger();
	// cin >> t;
	while(t-- > 0)
	{
		int n = inputInteger();
		// scanf("%d", &n);
		int p = 5;
		int s = n/p;
		int numZ = 0;
		while(s!=0)
		{
			numZ += s;
			p = p*5;
			s = n/p;
		}
		printf("%d\n", numZ);
	}
	return 0;
}