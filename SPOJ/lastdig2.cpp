#include <stdio.h>
#include <cstring>
#define getNum(n) scanf("%lld",&n)
int main()
{
	long long int t, a,b;
	getNum(t);
	int ar2[][4] = {{0,0,0,0},
				   {1,1,1,1},
				   {6,2,4,8},
				   {1,3,9,7},
					{6,4,6,4},{5,5,5,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};
	while(t--)
	{
		char str[1005];
		scanf("%s",str);
		a = str[strlen(str)-1]-'0';
		getNum(b);
		if(a==0)
			printf("0\n");
		else if(b==0)
			printf("1\n");
		else
			printf("%d\n",ar2[a][b%4]);
	}
	return 0;
}