#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)
#define getStr(st) scanf("%s",st)

int main()
{
	int n34 = 0, n12 = 0, n14 = 0;
	int n; getNum(n);
	int p=1;
	while(n--)
	{
		char ch[4];
		getStr(ch);
		if(ch[0]=='1' && ch[2]=='2')
			n12++;
		else if(ch[0]=='1' && ch[2]=='4')
			n14++;
		else
			n34++;
	}
	p+=n34;
	int spare14 = n34;
	if(n12%2==0)
		p+=(n12/2);
	else
	{
		p+=((n12/2)+1);
		spare14+=2;
	}
	if(n14>spare14)
	{
		n14-=spare14;
		p+=((n14/4)+1);
	}
	printf("%d\n",p);
	return 0;
}