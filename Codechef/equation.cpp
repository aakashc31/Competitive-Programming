#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int t;
	getNum(t);
	while(t-- > 0)
	{
		int n,a,b,c;
		getNum(n);
		getNum(a);
		getNum(b);
		getNum(c);
		int a1 = (a>b)?a:b; //max(a,b)
		int a2 = (a>b)?b:a;//min(a,b);
		int a3 = a1>c ?a1:c; //largest
		int a4 = a1>c ?c:a1; //other
		long long int s = 0;
		f(i,a2+1)
		{
			f(j,a4+1)
			{
				int k = n-i-j;
				if(k<0)
				{}
				else if(k<=a3)
				{
					s+=(k+1);
				}
				else
				{
					s+=(a3+1);
				}
			}
		}
		printf("%lld\n",s);

	}
	return 0;
}