// even fibonacci sum till n
// test cases 10^5, n: 4* 10^16
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define getLong(n) scanf("%lld",&n)
typedef long long int lli;

vector<lli> fibs(0); //contain even fibs till n

void stor_fibs_till_n()
{
	lli max = 40000000000000000;
	lli a,b,s;
	a = 1;
	b = 2;
	fibs.push_back(b);
	s = a+b;
	while(s<=max)
	{
		if(s%2 == 0)
			fibs.push_back(s);
		a = b;
		b = s;
		s = a+b;
	}
}

lli sum_fib_till_n(lli n)
{
	lli s = 0;
	int i = 0;
	while(i< fibs.size())
	{
		if(fibs[i] > n)
			break;
		s+=fibs[i];
		i++;
	}
	return s;
}

int main()
{
	stor_fibs_till_n();
	int t;
	getNum(t);
	while(t--)
	{
		lli n;
		getLong(n);
		printf("%lld\n",sum_fib_till_n(n));
	}
	return 0;
}


