// #include <iostream>
#include <stdio.h>
// using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar_unlocked()
#define outch putchar_unlocked
// #define inpch getchar()
// #define outch putchar
#define getNum(n) scanf("%d",&n)
short int r=0;
char ch;
short int inputInteger()
{
	ch = inpch;
	r =0;
	while(ch!='\n' && ch!=' ')
	{
		r = r*10 + ch-'0';
		ch = inpch;
	}
	return r;
}
short int t,n,s,a,b;
int main()
{
	t = inputInteger();
	while(t--)
	{
		n = inputInteger();
		s=0;
		while(n--)
		{
			a = inputInteger(), b = inputInteger();
			s+=(a-b);
		}
		printf("%d\n",s);
	}
	return 0;
}