#include <iostream>
#include <stdio.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
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

struct node
{
	int lazy,mod0,mod1,mod2;
}ar[500009];

void initiate(int i, int l, int r)
{
	int mid = (l+r)/2;
	ar[i].mod0 = r-l+1;
	ar[i].mod1 = 0;
	ar[i].mod2 = 0;
	ar[i].lazy = 0;
	if(l!=r)
	{
		initiate(2*i, l,mid);
		initiate(2*i+1,mid+1,r);
	}
}

int query(int i, int il, int ir, int from, int to)
{
	int laztmp = (ar[i].lazy);
	if(laztmp!=0)
	{
		ar[i].lazy=0;
		if(laztmp%3==1)
		{
			int temp = ar[i].mod0;
			ar[i].mod0 = ar[i].mod2;
			ar[i].mod2 = ar[i].mod1;
			ar[i].mod1 = temp;
		}
		else if(laztmp%3==2)
		{
			int temp = ar[i].mod0;
			ar[i].mod0 = ar[i].mod1;
			ar[i].mod1 = ar[i].mod2;
			ar[i].mod2 = temp;
		}
		if(il<ir)
		{
			ar[2*i].lazy+=laztmp;
			ar[2*i+1].lazy+=laztmp;
		}
	}
	if(il>to || ir<from)
		return 0;
	else if(il>=from && ir<=to)
		return ar[i].mod0;
	else
	{
		int mid = (il+ir)/2;
		return query(2*i,il,mid,from,to)+query(2*i+1,mid+1,ir,from,to);
	}
}

void update(int i, int il, int ir, int from, int to)
{
	int laztmp = (ar[i].lazy);
	if(laztmp!=0)
	{
		ar[i].lazy=0;
		if(laztmp%3==1)
		{
			int temp = ar[i].mod0;
			ar[i].mod0 = ar[i].mod2;
			ar[i].mod2 = ar[i].mod1;
			ar[i].mod1 = temp;
		}
		else if(laztmp%3==2)
		{
			int temp = ar[i].mod0;
			ar[i].mod0 = ar[i].mod1;
			ar[i].mod1 = ar[i].mod2;
			ar[i].mod2 = temp;
		}
		// pass laziness on to children
		if(il<ir)
		{
			ar[2*i].lazy+=laztmp;
			ar[2*i+1].lazy+=laztmp;
		}
	}
	if(il>to || ir<from) //not in range
		return;
	else if(il>=from && ir<=to) //completely in range
	{
		int temp = ar[i].mod0;
		ar[i].mod0 = ar[i].mod2;
		ar[i].mod2 = ar[i].mod1;
		ar[i].mod1 = temp;
		if(il<ir)
		{
			ar[2*i].lazy++;
			ar[2*i+1].lazy++;
		}
	}
	else
	{
		int mid = (il+ir)/2;
		update(2*i,il,mid,from,to);
		update(2*i+1,mid+1,ir,from,to);
		ar[i].mod0 = ar[2*i].mod0 + ar[2*i+1].mod0;
		ar[i].mod1 = ar[2*i].mod1 + ar[2*i+1].mod1;
		ar[i].mod2 = ar[2*i].mod2 + ar[2*i+1].mod2;
	}

}

int main()
{
	int n=inputInteger(), q=inputInteger();
	int ch,a,b;
	initiate(1,0,n-1);
	while(q--)
	{
		ch=inputInteger(), a=inputInteger(), b=inputInteger();
		if(ch==0)
			update(1,0,n-1,a,b);
		else
			printf("%d\n",query(1,0,n-1,a,b));
	}
	return 0;
}
