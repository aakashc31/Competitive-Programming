#include <stdio.h>
#include <cstring>
#define getNum(n) scanf("%d",&n)


int abs(int a)
{
	if(a<0)
		return -a;
	else 
		return a;
}
int main()
{
	int t,l,r,s;
	char ch[10001];
	getNum(t);
	while(t--)
	{
		s=0;
		scanf("%s",ch);
		r = strlen(ch)-1;
		l=0;
		while(l<=r)
		{
			s += abs(ch[r]-ch[l]);
			l++,r--;
		}
		printf("%d\n",s);
	}
	return 0;
}