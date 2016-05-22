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

void inputString(char* str)
{
	char ch = inpch;
	while(ch=='\n' || ch==' ') ch = inpch;
	register int i = 0;
	while(ch!='\n' && ch!=' ')
	{
		str[i++] = ch;
		ch = inpch;
	}
	str[i] = '\0';
}


int main()
{
	int n = inputInteger();
	char str[201];
	while(n!=0)
	{
		inputString(str);
		//algo begin
		int l = strlen(str);
		f(offset,n)
		{
			f(i,l/n)
			{
				if(i%2 == 0)
					outch(str[n*i+offset]);
				else
					outch(str[n*i+n-1-offset]);
			}
		}
		outch('\n');
		//algo end
		n = inputInteger();
	}
	return 0;
}