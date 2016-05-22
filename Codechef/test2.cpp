#include <bits/stdc++.h>
using namespace std;

void test(int i, int j)
{
	int k=0;
	while(i<j)
	{
		k =0;
		while(i + (1<<k) <= j)
		{
			k++;
		}
		printf("%d, 2^%d\n",i,k-1);
		i += (1<<(k-1));
	}
}

int main()
{
	test(1,8);
	return 0;
}