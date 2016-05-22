#include <bits/stdc++.h>

#define f(i,n) for(int i=0; i<n; i++)
#define get(n) scanf("%d",&n)

int main()
{
	int n;
	get(n);
	int var = 2;
	int toDraw = 1;
	f(i,n)
	{
		int stars = (n-toDraw)/2;
		f(j,stars)
			printf("*");
		f(j,toDraw)
			printf("D");
		f(j,stars)
			printf("*");
		toDraw+=var;
		if(toDraw>n)
		{
			toDraw-=4;
			var=-2;
		}
		printf("\n");
	}
	return 0;
}