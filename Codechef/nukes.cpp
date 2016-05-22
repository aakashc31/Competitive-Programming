#include <iostream>
#include <stdio.h>

using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int a,n,k;
	getNum(a); //number of bombarding
	getNum(n); //max jo ho sakta hai
	getNum(k); //no. of reactors
	int ar[k];
	f(i,k)
		ar[i] = 0;
	int i=0;
	while(a>0)
	{
		ar[i] = a%(n+1);
		a = a/(n+1);
		i++;
		if(i==k)
			break;
	}
	f(i,k)
		printf("%d ",ar[i]);
	printf("\n");
	return 0;
}