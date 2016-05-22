#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<float,float> pff;
typedef long long int ll;
#define g(n) scanf("%lld",&n)
#define f(i,n) for(int i=0; i<n; i++)
const int size = 5000001;
double ar[size];
void init()
{
	ar[0] = ar[1] = 0.0;
	for(int i=2; i<size; i++)
		ar[i] = ar[i-1] +sqrt(double(4*i - 3)); 	
}
double integ(double i)
{
	double a = sqrt(4*i+1);
	a = pow(a,3);
	return a/6.0;
}

double fun(double n)
{
	return integ(n-1) - integ(1);
}

double get_ans(double n)
{
	return ((fun(n) + n-1)/(2*n));
}

int main()
{
	init();
	ll t,n;
	g(t);
	while(t--)
	{
		g(n);
		if(n==0)
			printf("0\n");
		else if(n<size)
		{
			double ans = (n-1 + ar[n])/(2*n);
			printf("%.11lf\n",ans);
		}
		else
		{
			double num = n;
			printf("%.11lf\n",get_ans(num));
		}
	}
	return 0;
}