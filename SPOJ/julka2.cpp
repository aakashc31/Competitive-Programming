#include <iostream>
#include <stdio.h>
#include <cstring>
#define f(i,n) for(int i=0; i<n;i++)
#define getStr(s) scanf("%s",s)



void store_string(char ch[120], int ar[120])
{
	int l = strlen(ch);
	int len = l;
	int i=0;
	while(l>0)
	{
		ar[i] = ch[l-1] - '0';
		i++, l--;
	}
	while(len<120)
		ar[len++] = 0;
}

void print(int ar[120])
{
	int l=119;
	while(ar[l]==0)
		l--;
	while(l>=0)
		printf("%d",ar[l]), l--;
	printf("\n");
}

void add(int a[120], int b[120], int s[120])
{
	int carry = 0;
	f(i,120)
	{
		int temp = a[i] + b[i] + carry;
		s[i] = temp%10;
		carry = temp/10;
	}
}

void subtract(int a[120], int b[120], int d[120])
{
	int carry = 0;
	f(i,120)
	{
		int diff = a[i] - b[i] - carry;
		if(diff < 0)
		{
			diff+=10;
			carry = 1;
			d[i] = diff;
		}
		else
		{
			d[i] = diff;
			carry = 0;
		}
	}
}

void divide_by_2(int a[120])
{
	int carry = 0;
	for(int i=119; i>=0; i--)
	{
		int s = (10*carry + a[i]);
		a[i] = s/2;
		carry = s%2;
	}
}

int n[120];
int k[120];
int sum[120];
int main()
{
	int t=10;
	while(t--)
	{
		char ch[120];
		getStr(ch);
		store_string(ch,n);
		getStr(ch);
		store_string(ch,k);
		// print(n),print(k);
		add(n,k,sum); //sum = n+k
		// print(sum);
		divide_by_2(sum);
		print(sum);
		subtract(n,k,sum);
		// print(sum);	
		divide_by_2(sum);
		print(sum);
	}
	return 0;
}