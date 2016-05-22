// the problem which made me cry, coz the logic was simple: and the whole time I was looking for the wrong thing, I was not asking the wrong question. For that one variable, ar[pr] was written as ar[i], and all the time I did not check it. I changed everything above it, below it. But this! It took me approx 18 hrs. It cost me 2 night's sleep.
// Lesson: When you are sure about the algorithm, check the state transition (dry run). Like printing the state at each point, and trace the execution, and find out what is costing so much.


#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#include <map>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)
#define modulo 1000000007;


int ar[100001];
int main()
{
	int t,n;
	getNum(t);

	while(t--)
	{
		long long int ans = 1;
		bitset<100001> iscalc;
		// int u = 0, max=0;
		getNum(n);
		f(i,n)
		{
			getNum(ar[i+1]);
		}
		for(int i=1;i<=n;i++)
		{
			if(iscalc[i])
				continue;
			iscalc[i] = 1;
			int pr = ar[i];
			int t = 1;
			while(pr!=i)
			{
				iscalc[i] = 1;
				t++;
				pr = ar[pr];
			}
			ans = (ans*t)%1000000007;
		}
		
		printf("%lld\n",ans);
	}
	return 0;

}
