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
int ar[10000];

int main()
{
	int n; getNum(n);
	while(n!=-1)
	{
		int s=0;
		f(i,n){
			// ar[i] = inputInteger();
			getNum(ar[i]);
			s+=ar[i];
		}
		if(s%n==0)
		{
			int avg = s/n;
			int st = 0;
			f(i,n)
			{
				if(ar[i]>avg)
					st+=(ar[i]-avg);
			}
			printf("%d\n",st);
		}
		else
			printf("-1\n");
		getNum(n);
	}
	return 0;
}