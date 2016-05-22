#include <iostream>
#include <stdio.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

int main()
{
	int n;
	scanf("%d",&n);
	int sum1,sum2;
	sum1 = sum2 = 0;
	int winner=0;
	int lead = 0;
	f(i,n)
	{
		int si,ti;
		scanf("%d",&si);
		scanf("%d",&ti);
		sum1+=si;
		sum2+=ti;
		int diff = sum1 > sum2 ? sum1-sum2:sum2-sum1;
		if(diff > lead)
		{
			lead = diff;
			winner = sum1 > sum2 ? 1:2;
		}
	}
	printf("%d %d", winner,lead);
	return 0;
}