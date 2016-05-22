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

// this function is working correctly. Checked.
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

// working just fine
void compute_expec(lli a, lli b)
{
	lli sum = sum_of_ones_till(b) - sum_of_ones_till(a-1);
	double exp = (double(sum))/(b-a+1);
	printf("%.5f\n",exp);
}

// there was a bug, crushed it.
double prob_for_fixed_length(lli t)
{
	lli x = t-1;
	lli num1s = pow(2,x);
	num1s = num1s + x*(num1s/2);
	double prob = (double(num1s))/t;
	return prob;
}

void compute_prob(lli a, lli b)
{
	int l1 = num_dig_in_binary(a);
	int l2 = num_dig_in_binary(b);
	if(l1==l2)
	{
		lli num1s = sum_of_ones_till(b) - sum_of_ones_till(a-1);
		double prob = (double(num1s))/(l1*(b-a+1));
		printf("%.5f ",prob);
	}
	else
	{
		lli from_a_to_max = sum_of_ones_till((lli)(pow(2,l1)-1)) - sum_of_ones_till(a-1);
		double s = (double(from_a_to_max))/l1;
		l1++;
		while(l1<l2)
		{
			s+= prob_for_fixed_length(l1);
			l1++;
		}
		lli to_b = sum_of_ones_till(b) - sum_of_ones_till((lli(pow(2,l2-1)))-1);
		s+= (double(to_b)/l2);
		s/=(b-a+1);
		printf("%.5f ",s);
	}
}

int main()
{
	lli t,a,b;
	getNum(t);
	while(t--)
	{
		getNum(a), getNum(b);
		compute_prob(a,b); 
		compute_expec(a,b);
	}
	return 0;
}