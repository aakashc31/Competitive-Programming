#include <stdio.h>
#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)

void print_array(int ar[], int left, int right)
{
	f(i,right-left+1)
		printf("%d ", ar[left+i]);
	printf("\n");
}

void insert_last(int ar[], int size)
{
	int i = size-1;
	int element = ar[i];
	i--;
	while(i>=0 && ar[i] > element)
	{
		ar[i+1] = ar[i];
		i--;
		print_array(ar,0,size-1);
	}
	ar[i+1] = element;
	print_array(ar,0,size-1);
}

int main()
{
	int s;
	getNum(s);
	int ar[s];
	f(i,s)
		getNum(ar[i]);
	insert_last(ar,s);
	return 0;
}