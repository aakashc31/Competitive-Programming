#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
#define mp make_pair

char *ch;
char rev[50001];
bool ispal(char* ch, int i, int j)
{
	while(i<j)
	{
		if(ch[i]!=ch[j])
			return false;
		i++,j--;
	}
	return true;
}
int main()
{
	scanf("%s",rev);
	int l = strlen(rev);

	int low=0,high=l-1;
	while(rev[low]==rev[high])
		low++,high--;
	rev[high+1]='\0';
	ch = rev+low;
	l = high-low+1;

	bool flag = false;
	char c = ch[0];
	int j=1;
	while(j<l)
	{
		if(ch[j]==c)
		{
			bool fr = true;
			f(i,j)
			{
				if(ch[i]!=ch[j+i])
				{
					fr = false;
					break;
				}
			}
			if(fr)
			{
				if(ispal(ch,2*j,l-1))
				{
					flag = true;
					break;
				}
			}
		}
		j++;
	}

	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}