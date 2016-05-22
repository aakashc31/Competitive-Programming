#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
const int modulo = 1000000007;
char ch[100005];

int getVal(bool isOddLayer, int num, char next)
{
	if(isOddLayer)
	{
		if(next=='l')
			return (2*num)%modulo;
		else
			return (2*num+2)%modulo;
	}
	else
	{
		if(next=='l')
			return (2*num-1)%modulo;
		else
			return (2*num+1)%modulo;
	}
}

void get()
{
	int l = strlen(ch);
	int ans=1;
	f(i,l)
		ans = getVal(!(i&1), ans, ch[i]);
	printf("%d\n",ans );
}

int main()
{
	int t;
	g(t);
	while(t--)
	{
		scanf("%s",ch);
		get();
	}
	return 0;
}