#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)


int gcd(int a,int b)
{
	if(b==0)
		return a;
	else if(a==0)
		return b;
	else
		return gcd(b,a%b);
}
int main()
{
	int n;
	getNum(n);
	int ar[n];
	f(i,n)
		getNum(ar[i]);
	int s = 0;
	f(i,n-2)
	{
		for(int j=i+1; j<n-1; j++)
		{
			int g = gcd(ar[i],ar[j]);
			if(g==1)
				s+=(n-1-j);
			else
			{
				for(int k=j+1; k<n;k++)
				{
					int ngcd = gcd(g,ar[k]);
					if(ngcd==1)
						s++;
				}
			}
		}
	}
	printf("%d\n",s);
	return 0;
}