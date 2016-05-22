#include <iostream>
#include <stdio.h>
#include <cmath>
#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0;i<n;i++)
typedef long long int lli;

lli num_dig_in_binary(lli n)
{
	if(n==0)
		return 0;
	lli r = log2(n);
	return r+1;
}
lli sum_of_ones_till(lli n)
{
	if(n<=0)
		return 0;
	lli s = 0;
	lli l = num_dig_in_binary(n);
	f(i,l-1)
	{
		lli place = i+1;
		lli nearest_power = pow(2,place);
		lli temp = (n+1)/(nearest_power);
		temp*= (nearest_power/2); 
		lli t = (n+1)%(nearest_power); 
		if(t > (nearest_power/2))
			temp+= (t- (nearest_power/2 ));
		s+=temp;
	}
	s+=(n-pow(2,l-1) + 1);
	return s;
}
lli neg_sum_ones(lli n)
{
	lli min = pow(2,31)-n;
	// printf("min: %lld\n",min);
	lli max = pow(2,31) - 1;
	// printf("max: %lld\n",max);
	lli t = sum_of_ones_till(max) - sum_of_ones_till(min-1) + n;
	return t;
}

int main()
{
	lli t,a,b;
	getNum(t);
	while(t--)
	{
		getNum(a), getNum(b);
		if(a>=0 && b>=0)
			printf("%lld\n",(sum_of_ones_till(b)-sum_of_ones_till(a-1)));
		else if(b<0)
			printf("%lld\n",(neg_sum_ones(-a)-neg_sum_ones(1-b)));
		else
			printf("%lld\n",(sum_of_ones_till(b) + neg_sum_ones(-a)));
	}

	return 0;
}