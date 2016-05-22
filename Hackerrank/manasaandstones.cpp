#include <bits/stdc++.h>

using namespace std;

#define get(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)

bitset<1000000> visit;

int main()
{
	int t,n,a,b;
	get(t);
	while(t--)
	{
		get(n);
		get(a),get(b);
		if(a==b)
		{
			printf("%d\n",(n-1)*a);
			continue;
		}
		visit.set();
		visit.flip(); //all 0
		int max=0;
		f(i,n)
		{
			int temp = i*a + (n-1-i)*b;
			visit[temp-1]=1;
			if(temp>max)
				max=temp;
		}
		f(i,max)
		{
			if(visit[i])
				printf("%d ",i+1);
		}
		printf("\n");
	}
	return 0;
}
