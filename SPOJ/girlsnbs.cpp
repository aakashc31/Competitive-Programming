#include <stdio.h>
#include <algorithm>
using namespace std;
#define getNum(n) scanf("%d",&n)

int main()
{
	int a,b;
	getNum(a);getNum(b);
	while(a!=-1 || b!=-1)
	{
		int bs = max(a,b);
		int gs = min(a,b);
		if(bs==0 && gs==0)
			printf("0\n");
		else if(bs-gs <= 1)
		{
			printf("1\n");
		}
		else
		{
			int s=0;
			while(bs>0)
			{
				bs-=(gs+1);
				s++;
			}
			printf("%d\n",s);
		}
		getNum(a);getNum(b);
	}
	return 0;
}