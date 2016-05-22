#include <cstdio>
#include <bitset>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)

bitset<100000> isU;
int main()
{
	int t,n,num;
	getNum(t);
	while(t--)
	{
		isU.set();
		isU.flip();
		getNum(n);
		int numDist = 0;
		f(i,n) 
		{
			getNum(num);
			if(!isU[num-1])
			{
				isU[num-1] = 1;
				numDist++;
			}
		}
		printf("%d\n",numDist);
	}
	return 0;
}