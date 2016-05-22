#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
#define getNum(n) scanf("%d",&n)

int inputInteger()
{
	char ch = inpch;
	register int r=0;
	while(ch!='\n' && ch!=' ')
	{
		r = (r<<1) + (r<<3) + ch-'0';
		ch = inpch;
	}
	return r;
}
int main()
{
	int t = inputInteger();
	// cin >> t;
	while(t-- > 0)
	{
		int n = inputInteger();
		// cin >> n;
		int ar[50];
		int m = 1; //length
		f(i,50)
			ar[i] = 0;
		ar[0] = 1;

		for(int i=2; i<=n; i++)
		{
			//multiply i to the number represented by ar
			int carry = 0;
			f(j,m)
			{
				int x = ar[j]*i + carry;
				carry = x/10000;
				ar[j] = x%10000;
			}
			while(carry!=0)
			{
				ar[m] = carry%10000;
				carry /= 10000;
				m++;
			}
		}
		// cout << ar[m-1];
		printf("%d",ar[m-1]);
		for(int i=m-2; i>=0; i--)
		{
			int t = ar[i];
			if(t==0)
				cout << "0000";
			else if(t<10)
				cout << "000" << t;
			else if(t<100)
				cout << "00" << t;
			else if(t<1000)
				cout << "0" << t;
			else
				cout << t;
		}
		printf("\n");
	}
	return 0;
}
