#include <stdio.h>
#include <algorithm>
// #include <vector>
#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int t;
	getNum(t);
	f(i,t)
	{
		//i+1 th scenario
		int need, numF;
		getNum(need); getNum(numF);
		int s=0;
		int ar[numF];
		f(j,numF)
		{
			getNum(ar[j]);
			s+=ar[j];
		}
		if(s<need)
			printf("Scenario #%d:\nimpossible\n\n",i+1);
		else
		{
			s=need;
			std::sort(ar,ar+numF);
			int k=0;
			while(s>0)
			{	
				s-=ar[numF-1-k];
				k++;
			}
			printf("Scenario #%d:\n%d\n\n",i+1,k);
		}

	}
	return 0;
}