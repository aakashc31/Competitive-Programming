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

struct chef
{
	int id,max,lost_to;	
};

struct dish
{
	int score;
	chef* c;
}ar[10000];

int find(int x)
{
	chef* c = ar[x].c;
	if(c->lost_to == c->id)
		return c->id;
	else
	{
		int p = find(c->lost_to);
		c->lost_to = p;
		return p;
	}
}

void update(int x, int y)
{
	chef *c1 = ar[find(x)].c;
	chef *c2 = ar[find(y)].c;
	int m1 = c1->max;
	int m2 = c2->max;
	if(c1->id == c2->id)
	{
		printf("Invalid query!\n");
	}
	else if(m1>m2)
	{
		// ar[y].c = ar[x].c; //this is the error
		c2->lost_to = c1->id;
	}
	else if(m1<m2)
	{
		// ar[x].c = ar[y].c;
		c1->lost_to = c2->id;
	}
}



int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int n; //number of dishes
		getNum(n);
		f(i,n)
		{
			int tmp;
			getNum(tmp);
			ar[i].score = tmp;
			ar[i].c = new chef;
			ar[i].c -> id = i;
			ar[i].c -> max = tmp;
			ar[i].c ->lost_to = i;
		}
		int q;//number of queries
		getNum(q);
		while(q--)
		{
			int mode;
			getNum(mode);
			if(mode==0)
			{
				int x,y;
				getNum(x);getNum(y);
				update(x-1,y-1);
			}
			else
			{
				int x;
				getNum(x);
				printf("%d\n",find(x-1)+1);
			}
		}
	}
	return 0;
}
