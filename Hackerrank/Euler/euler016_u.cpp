#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

int ar[3100];
void init()
{
	f(i,3100)
		ar[i] = 0;
	ar[0] = 1;
}

int sum_ar()
{
	int s = 0;
	f(i,3100)
		s+=ar[i];
	return s;
}

void multiply_by_const(int num)
{
	int carry = 0;
	f(i,3100)
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
		int p = n/10;
		int r =  n%10;
		f(i,p)
			multiply_by_const(pow(2,10));
		multiply_by_const(pow(2,r));
		// print();
		printf("%d\n",sum_ar());
	}
	return 0;
}