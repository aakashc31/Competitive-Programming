#include <iostream>
#include <cstring>
//#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

#define f(i,n) for(lli i=0; i<n; i++)
#define fab(i,a,b) for(lli i=a;i<=b;i++)
#define getNum(n) scanf("%lld",&n)

typedef long long int lli;
lli neg(lli a)
{
	lli c = -1*a;
	return c;
}
lli max(lli a, lli b)
{
	if(a>b)
		return a;
	else
		return b;
}

lli absolute(lli a)
{
	if(a<0)
		return neg(a);
	else
		return a;
}

lli get_max_val(lli n, lli k, lli t1, lli t2)
{
	lli a = (k+(2*t1)+t2)/3;
	lli b = (k-t1+t2)/3;
	lli c = (k-t1-(2*t2))/3;
	lli sum = (n-a) + (n-b) + (n-c);
	if(((a+b+c) == k) && a>=0 && b>=0 && c>=0 && a<=n && b<=n && c<=n && (sum == 3*n-k) && (absolute(a-b)==absolute(t1)) && absolute(b-c)==absolute(t2))
	{
		lli d = max(a,b);
		d = max(d,c);
		return d;
	}
	return -1;
}

int main()
{
	lli t,n,k,d1,d2;
	getNum(t);
	while(t--)
	{
		getNum(n), getNum(k), getNum(d1), getNum(d2);
		if(n%3!=0)
		{
			printf("no\n");
			continue;
		}
		n/=3;
		lli c1 = get_max_val(n,k,d1,d2);
		
		bool flag = false;
		
		// printf("%lld\n",c1 );
		if(c1<=n && c1!=-1)
		{
			// printf("1%lld\n",c1);
			flag = true;
		}
		c1 = get_max_val(n,k,d1,neg(d2));
		
		// printf("%lld\n",c1 );
		if(c1<=n && c1!=-1)
		{
			// printf("2%lld\n",c1);
			flag = true;
		}
		

		c1 = get_max_val(n,k,neg(d1),neg(d2));
		
		// printf("%lld\n",c1 );
		if(c1<=n && c1!=-1)
		{
			// printf("3%lld\n",c1);
			flag = true;
		}
		c1 = get_max_val(n,k,neg(d1),d2);
		
		// printf("%lld\n",c1 );
		if(c1<=n && c1!=-1)
		{
			// printf("4%lld\n",c1);
			flag = true;
		}
		if(flag)
			printf("yes");
		else
			printf("no");
		if(t>0)
			printf("\n");

	}
	return 0;
}
