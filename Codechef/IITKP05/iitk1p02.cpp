#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)

int awesomeness(char* ch, char c)
{
	int len = 0, ret = 0;
	f(i,strlen(ch))
	{
		if(ch[i]==c)
			len++;
		else
			len=0;
		if(len>ret)
			ret=len;
	}
	return ret;
}

int main()
{
	char ch[100001];
	scanf("%s",ch);
	int val = 0;
	char c = '\0';
	f(i,26)
	{
		int tmp = awesomeness(ch,'a'+i);
		if(tmp > val)
		{
			val = tmp;
			c = 'a'+i;
		}
	}
	printf("%c\n%d\n",c,val);
	return 0;
}