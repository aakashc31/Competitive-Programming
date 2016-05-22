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


int main()
{
	int t,n;
	// t = inputInteger();
	scanf("%d",&t);
	int ar[26], br[26], same[26], diff[26];
	while(t--)
	{
		// n = inputInteger();
		// getchar();
		scanf("%d",&n);
		f(i,26) br[i] = same[i] = ar[i] = diff[i] = 0;
		int vary = 0;
		int numofstr = n;
		while(n--)
		{
			char str[1001];
			scanf("%s",str);
			int l = strlen(str);
			int beg = str[0]-97, end = str[l-1]-97;
			if(beg==end)
			{
				same[beg]++;	
				vary++;
				continue;
			}
			ar[beg]++;
			br[end]++;
		}
		f(i,26) diff[i] = ar[i]-br[i];
		int nz = 0, n1 = 0, n2 = 0;
		if(vary==numofstr)
		{
			f(i,26)
			{
				if(same[i]==0)
					nz++;
			}
			if(nz==25)
			{
				printf("Ordering is possible.\n");
				continue;
			}
			else
			{
				printf("The door cannot be opened.\n");
				continue;
			}
		}
		f(i,26)
		{
			if(diff[i]==0)
				nz++;
			else if(diff[i]==1)
				n1++;
			else if(diff[i]==-1)
				n2++;
		}
		if(nz==24 && n1 == 1 && n2==1 || nz==26)
		{
			bool flag = true;
			f(i,26)
			{
				if(same[i]!=0 && ar[i]==0 && br[i]==0)
				{
					flag = false;
					break;
				}
			}
			if(flag)
				printf("Ordering is possible.\n");
			else
				printf("The door cannot be opened.\n");
		}
		else
			printf("The door cannot be opened.\n");
	}
	return 0;
}
