#include <stdio.h>
#include <cmath>
using namespace std;
#define getNum(n) scanf("%d",&n)
int main()
{
	int n;
	getNum(n);
	while(n!=0)
	{
		double t = n*n;
		double c = (t)/(2*(M_PI));
		printf("%.2f\n",c);
		getNum(n);
	}
	return 0;
}