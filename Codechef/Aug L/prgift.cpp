#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define get(n) scanf("%d",&n)

int main()
{
	int t,n,k,temp,s;
	get(t);
	while(t--)
	{
		s=0;
		get(n), get(k);
		f(i,n)
		{
			get(temp);
			if((temp%2==0))
				s++;
		}
		if(k==0)
		{
			if(s==n)
				printf("NO\n");
			else 
				printf("YES\n");
		}
		else if(s>=k)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}