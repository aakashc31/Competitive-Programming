#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define get(n) scanf("%d",&n)

int sumOfDivisors(int n)
{
	int cp = n;
	int s=1;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int temp=0;
			while(n%i==0)
			{
				n/=i;
				temp++;
			}
			s*=((pow(i,temp+1)-1)/(i-1));
		}
	}
	if(n>1)
	{
		s*=(n+1);
	}
	return s-cp;
}

int ar[25000];
int size=0;

void init()
{
	f(i,100000)
	{
		if(sumOfDivisors(i+1)>i+1)
		{
			ar[size]=i+1;
			size++;
		}
	}
	// printf("%d\n",size);
}

bool search(int n)
{
	f(i,size)
	{
		int t = n-ar[i];
		if(binary_search(ar,ar+size,t))
			return true;
	}
	return false;
}

int main()
{
	init();
	int t,n;
	get(t);
	while(t--)
	{
		get(n);
		if(search(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}