#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int t;
	getNum(t);
	while(t-- > 0)
	{
		int n;
		getNum(n);
		char ch[n];
		scanf("%s",ch);
		bool isExploded[n];
		f(i,n)
			isExploded[i] = false;
		f(i,n)
		{
			if(ch[i] == '1')
			{
				if(i==0)
					isExploded[0] = isExploded[1] = true;
				if(i==n-1)
					isExploded[i] = isExploded[i-1] = true;
				else
					isExploded[i-1] = isExploded[i] = isExploded[i+1] = true;
			}
		}
		int ans = 0;
		f(i,n)
		{
			if(!isExploded[i])
				ans++;
		}
		printf("%d\n",ans );	
	}
}