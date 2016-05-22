#include <stdio.h>
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
int inputInteger()
{
	char ch = inpch;
	register int r=0;
	while(ch!='\n' && ch!=' ')
	{
		r = (r<<1) + (r<<3) + ch-'0';
		ch = inpch;
	}
	return r;
}

int main()
{
	int t, a,b;
	t= inputInteger();
	int ar2[][4] = {{0,0,0,0},
				   {1,1,1,1},
				   {6,2,4,8},
				   {1,3,9,7},
					{6,4,6,4},{5,5,5,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};
	while(t--)
	{
		a = inputInteger()%10;
		b = inputInteger()%4;

		if(a==0)
			printf("%d\n",a);
		else if(b==0)
			printf("1\n");
		else
			printf("%d\n",ar2[a][b]);
	}
	return 0;
}