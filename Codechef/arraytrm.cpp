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
	int t,n,k,ar;
	t = inputInteger();
	while(t--)
	{
		n=inputInteger(); 
		// cout << n << endl;
		k = inputInteger();
		// cout << k <<endl;

		int mod[k+1];
		f(i,k+1)
			mod[i]=0;
		f(i,n)
		{
			ar = inputInteger();
			mod[ar%(k+1)]++;
		}
		if(n==2)
		{
			printf("YES\n");
			continue;
		}
		int a=0,b=0,c=0;
		f(i,k+1)
		{
			if(mod[i]==1)
				a++;
			else if(mod[i]==n-1)
				b++;
			else if(mod[i]==n)
				c++;
		}
		if(a==1 && b==1 || c==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}