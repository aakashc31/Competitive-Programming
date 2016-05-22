#include <stdio.h>
#include <cstring>
#include <cmath>
#define f(i,n) for(int i=0; i<n;i++)
#define getStr(st) scanf("%s",st)

typedef long long int lli;

// this function converts ch[i..j] to integer
lli con(char ch[], int i, int j)
{
	lli s=0;
	for(int k=i;k<=j;k++)
		s = s*10 + (ch[k] - '0');
	return s;
}

lli n[10];
lli k[10];

// adds a and b and stores in c
void add(lli a[], lli b[], lli c[])
{
	lli carry = 0;
	int i=0;
	for(;i<10;i++)
	{
		lli t = a[i] + b[i] + carry;
		c[i] = t%((lli)(pow(10,10)));
		carry = t/((lli)(pow(10,10)));
	}
	c[i] = carry;
}

// c/=2
void divby2(lli c[], int l)
{
	int carry=0;
	for(int i=l; i>=0;i--)
	{
		lli t = carry*(pow(10,10)) +  c[i];
		c[i] = t/2;
		carry = t%2;
	}
}

// c = a-b
void subtract(lli a[], lli b[], lli c[])
{
	f(i,10)
	{
		lli t = a[i] - b[i];
		while(t<0)
		{
			t+=((lli)(pow(10,10)));
			a[i+1]--;
		}
		c[i] = t%((lli)(pow(10,10)));
		
	}
}

void printInTen(lli a)
{
	int len = log10(a);
	len++;
	// len is then number of digits in a
	f(i,10-len)
		printf("0");
	printf("%lld",a);
}

void print(lli c[], int l)
{
	while(c[l]==0)
		l--;
	bool flag = true;
	while(l>=0)
	{
		if(flag)
		{
			printf("%lld",c[l]);
			flag = false;
			l--;
			continue;
		}
		printInTen(c[l]);
		l--;
	}
	printf("\n");
}

int main()
{
	int t=10;
	while(t--)
	{
		f(i,10)
			n[i] = k[i] = 0;
		char ch[101];
		getStr(ch);
		int p = strlen(ch);
		int l = (p-1)/10;
		for(int i=0; i<=l; i++)
		{
			if(p<=10)
				n[i] = con(ch,0,p-1);
			else
				n[i] = con(ch,p-10,p-1);
			p-=10;
		}
		getStr(ch);
		p = strlen(ch);
		l = (p-1)/10;
		for(int i=0; i<=l; i++)
		{
			if(p<=10)
				k[i] = con(ch,0,p-1);
			else
				k[i] = con(ch,p-10,p-1);
			p-=10;
		}
		// print(n,10);
		// print(k,10);
		//input and converting into lli array over
		lli c[15]; lli d[15];
		f(i,15)
			c[i] = d[i] = 0;
		add(n,k,c);
		subtract(n,k,d);
		divby2(c,14);
		divby2(d,14);
		print(c,14);
		print(d,14);
	}
	return 0;
}