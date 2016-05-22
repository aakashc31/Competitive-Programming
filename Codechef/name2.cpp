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
		char m[25001];
		char w[25001];		
		scanf("%s",m);
		scanf("%s",w);
		int l1 = strlen(m);
		int l2 = strlen(w);
		fflush(stdin);
		if(strcmp(m,w)==0)
		{
			printf("YES\n");
			continue;
		}
		int i,j;
		i=0;j=0;
		bool flag = true;
		while(i<l1)
		{
			char ch = m[i];
			int k=j;
			if(k>=l2)
			{
				flag = false;
				break;
			}
			for(;k<l2;k++)
			{
				if(w[k]==ch)
					break;
			}
			if(k>=l2)
			{
				flag = false;
				break;
			}
			j = k+1;
			i+=1;
		}
		if(flag)
			printf("YES\n");
		else
		{
			int i,j;
			i=0;j=0;
			bool flag1 = true;
			while(i<l2)
			{
				char ch = w[i];
				int k=j;
				if(k>=l1)
				{
					flag1 = false;
					break;
				}
				for(;k<l1;k++)
				{
					if(m[k]==ch)
						break;
				}
				if(k>=l1)
				{
					flag1 = false;
					break;
				}
				j = k+1;
				i+=1;
			}

			if(flag1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}