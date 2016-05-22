#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#include <map>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)
typedef long long int lli;

int main()
{
	int t;
	getNum(t);
	char ar[] = {'A','G','C','T'};
	while(t--)
	{
		int n,m,k;
		getNum(n);getNum(m);getNum(k);
  		f(i,n)
  		{
  			f(j,m)
  			{
  				printf("%c",ar[(j+i)%4]);
  			}
  			printf("\n");
  		}
	}
	return 0;
}