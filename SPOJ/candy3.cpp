#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%lld",&n)

int main()
{
	long long int t,n;
	getNum(t);
	while(t--)
	{
		scanf("\n%lld",&n);
		long long int s=0;
		f(i,n)
		{
			long long int tmp; 
			getNum(tmp);
			tmp = tmp % n;
			s+=tmp;
			// s%=n;
		}
		if(s%n==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}