#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

const int size = 4000;
int ar[size];
void init()
{
	f(i,size)
		ar[i] = 0;
	ar[0] = 1;
}

int sum_ar()
{
	int s = 0;
	f(i,size)
		s+=ar[i];
	return s;
}

void multiply_by_const(int num)
{
	int carry = 0;
	f(i,size)
	{
		int t = ar[i]*num + carry;
		ar[i] = t%10;
		carry=t/10;
	}
}
void print()
{
	f(i,10)
		printf("%d",ar[9-i]);
	printf("\n");
}
int pow(int i, int p)
{
	if(p==0)
		return 1;
	if(p%2==0)
	{
		int half = pow(i,p/2);
		return half*half;
	}
	else
	{
		int half = pow(i,p/2);
		return half*half*i;
	}
}
int main()
{
	int t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		init(); //ar now stores 2^0
		for(int i=2;i<=n;i++)
			multiply_by_const(i);
		// print();
		printf("%d\n",sum_ar());
	}
	return 0;
}