#include <iostream>
#include <stdio.h>


#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
const int size = 100000000;
int ar[size];

void init()
{
	ar[0] = 0;
	ar[1] = 1;
	for(int i=2;i<size;i++)
	{
		ar[i] = ar[i/2] + i%2;
	}
}

int get_num_ones(int a)
{
	if(a>=size)
		return (get_num_ones(a/2) + a%2);
	else
		return ar[a];
}

int main()
{
	init();
	while(true)
	{
		int a; getNum(a);
		printf("%d\n",get_num_ones(a));
	}
}