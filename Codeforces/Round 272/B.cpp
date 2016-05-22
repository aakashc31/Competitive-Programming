#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)
long long int ncr(long n, long r)
{
	if(r>n || r<0)
		return 0;
	if(r > n-r)
		r = n-r;
	if(r==0)
		return 1;
	else if(r==1)
		return n;
	else if(n==r)
		return 1;
	long long s = 1.0;
	int aa = n-r+1;
	f(i,r)
	{
		s = s*(aa+i)/(i+1);
	}
	// long long int a =s;
	return s;
}
int main()
{
	char ar[15], br[15];
	scanf("%s",ar);
	scanf("%s",br);
	int l = strlen(ar);
	int n=0,toreach = 0, reached = 0,k;
	f(i,l)
	{
		if(br[i]=='?')
			n++;
		else
			reached += (br[i]=='+'? 1 : (-1));
		toreach += (ar[i]=='+'? 1 : (-1));
	}
	if(n==0)
	{
		if(reached == toreach)
			printf("1.000000000\n");
		else
			printf("0\n");
		return 0;
	}
	k = toreach - reached;
	
	if((n+k)&1)
	{
		printf("0\n");
		return 0;
	}
	k = (n+k)/2;
	double r = double(ncr(n,k));
	double den = (1 << n);
	printf("%.9lf\n",r/den);
	return 0;
}