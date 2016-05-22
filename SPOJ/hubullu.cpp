#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%d",&n)

int main()
{
	int t,n,p;
	g(t);
	while(t--)
	{
		g(n);
		g(p);
		if(p==0)
			printf("Airborne wins.\n");
		else
			printf("Pagfloyd wins.\n");
	}
	return 0;
}