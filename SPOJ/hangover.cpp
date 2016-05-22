#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	float n;
	scanf("%f",&n);
	while(n!=0.0)
	{
		float s=0.0;
		float i=2.0;
		while(s<n)
		{
			s+=(1.0/i);
			i+=1.0;
		}
		int numc = i-2;
		printf("%d card(s)\n",numc);
		scanf("%f",&n);
	}
	return 0;
}