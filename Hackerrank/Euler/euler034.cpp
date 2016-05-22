#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
bitset<100001> curious;
int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
void init()
{
	int mod = 0;
	for(int i=10; i<=100000; i++)
	{
		int temp = i;
		mod = 0;
		while(temp > 0)
		{
			mod += fact[temp%10]%i;
			temp/=10;
		}
		if(mod%i == 0)
			curious[i] = 1;
	}
}
int main()
{
	curious.set();
	curious.flip();
	init();
	// printf("Yo\n");
	int n;
	g(n);
	int s = 0;
	f(i,n)
		s += (curious[i]) ? i:0;
	printf("%d\n",s);
	return 0;
}