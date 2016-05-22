#include <stdio.h>
#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int ng,nm,max_ng=0, max_nm=0;
		scanf("\n%d",&ng);
		getNum(nm);
		while(ng--)
		{
			int temp;
			getNum(temp);
			if(temp>max_ng) max_ng = temp;
		}
		while(nm--)
		{
			int temp;
			getNum(temp);
			if(temp>max_nm) max_nm = temp;
		}
		if(max_nm > max_ng)
			printf("MechaGodzilla\n");
		else
			printf("Godzilla\n");
	}
	return 0;
}