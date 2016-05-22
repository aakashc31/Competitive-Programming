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

void printRPN(char* str, int left, int right)
{
	//base case
	if(right == left)
	{
		outch(str[left]);
		return;
	}
	if(right-left+1 == 5)
	{
		outch(str[left+1]);
		outch(str[left+3]);
		outch(str[left+2]);
		return;
	}
	//recursion
	int nparen = 0, subl2 =0;
	for(int i=left+1; i<=right-1; i++)
	{
		if(str[i] == '(')
		{
			nparen++;
		}
		else if(str[i] == ')')
		{
			nparen--;
			if(nparen==0)
			{
				subl2 = i;
				break;
			}
		}
		else if(str[i]>=97 && str[i]<=122 && nparen==0)
		{
			subl2 = i;
			break;
		}
	}
	printRPN(str,left+1, subl2);
	printRPN(str,subl2+2, right-1);
	outch(str[subl2+1]);
}

int main()
{
	int t = inputInteger();
	while(t--)
	{
		char str[401];
		inputString(str);
		int l = strlen(str);
		printRPN(str,0,l-1);
		outch('\n');
	}
	return 0;
}