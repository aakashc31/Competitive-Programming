#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
#define getNum(n) scanf("%d",&n)
typedef long long int lli;
void inputString(char* str)
{
	char ch = inpch;
	register int i=0;
	while(ch!='\n')
		str[i++] = ch, ch=inpch;
	str[i] = '\0';
}
map<pair<lli,lli>,lli> M;
char str[1000001];
int main()
{
	lli aNum=0, bNum=0, cNum=0;
	inputString(str);
	int l = strlen(str);
	lli s=0;
	pair<lli,lli> init(0,0);
	M[init]=1;
	f(i,l)
	{
		char ch = str[i];
		if(ch=='A')
			aNum++;
		else if(ch=='B')
			bNum++;
		else
			cNum++;
		lli d1 = aNum- bNum;
		lli d2 = bNum - cNum;
		pair<lli,lli> p(d1,d2);
		if(M.find(p)!=M.end())
		{
			lli a = (M.find(p)->second);
			s+=a;
			M[p] = a+1;
		}
		else
		{
			M[p] = 1;
		}
	}
	printf("%lld\n",s);
	return 0;
}