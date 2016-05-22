#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

int main()
{
	char ch[][9] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
	int l;
	char inp[10];
	getNum(l);
	scanf("%s",inp);

	f(i,8)
	{
		if(strlen(ch[i])==l)
		{
			bool flag = true;
			f(j,l)
			{
				if(inp[j]=='.')
					continue;
				else if(inp[j] != ch[i][j])
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				printf("%s\n",ch[i]);
				break;
			}
		}
	}
	return 0;
}