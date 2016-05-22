#include <iostream>
#include <stdio.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar_unlocked()
#define outch putchar_unlocked
#define getNum(n) scanf("%d",&n)
int inputInteger()
{
	char ch = inpch;
	int r=0;
	while(ch!='\n' && ch!=' ')
	{
		r = r*10 + ch-'0';
		ch = inpch;
	}
	return r;
}

int main()
{
	int t = inputInteger();
	while(t--)
	{
		int n = inputInteger();
		int s1=0,s2=0;
		while(n--)
		{
			int a = inputInteger(), b = inputInteger();
			s1+=a;
			s2+=b;
		}
		printf("%d\n",s1-s2);
	}
	return 0;
}