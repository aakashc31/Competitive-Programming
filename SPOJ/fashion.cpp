#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
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
	int t,s;
	// getNum(t);
	t = inputInteger();
	int m[1000], w[1000];
	int n;
	while(t--)
	{
		n = inputInteger();
		// getNum(n);
		f(i,n)
			m[i] = inputInteger();
			// getNum(m[i]);
		f(i,n)
			w[i] = inputInteger();
			// getNum(w[i]);
		s=0;
		sort(m,m+n);
		sort(w,w+n);
		f(i,n)
			s+=w[i]*m[i];
		printf("%d\n",s);
	}
	return 0;

}