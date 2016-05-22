#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)

bool isPandigitalMult(int n, int k)
{
	int ar[10];
	f(i,10) ar[i]=0;
	int s=0;
	int p=1;
	int cpy = n;
	while(p<=5)
	{
		bool f = false;
		while(n>0)
		{
			int d = n%10;
			// printf("d = %d\n",d);
			if(ar[d] == 1 || d>k || d==0)
				return false;
			ar[d]++;
			s++; //number of 1's in ar
			
			n/=10;
		}
		if(s==k)
		{
			f = true;
			break;
		}
		// if(f) break;
		p++;
		n = cpy*p;
	}
	return true;
}

int main()
{
	int n,k;
	g(n), g(k);
	for(int i=2; i<n;i++)
	{
		if(isPandigitalMult(i,k))
			printf("%d\n",i);
	}
	// while(true)
	// {
	// 	g(n), g(k);
	// 	cout << isPandigitalMult(n,k) <<endl;
	// }
	return 0;
}