#include <stdio.h>
#include <cstring>
#include <cmath>
#define getNum(n) scanf("%d",&n)
#define getStr(c) scanf("%s",c)
typedef long long int lli;
int gcd(int a,int b)
{
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b, a%b);
}
int cmp_mod(lli ar[], int l, int a)
{
	lli c = 0;
	while(l>=0)
	{
		lli tmp = ar[l] + c*(pow(10,10));
		c = tmp%a;
		l--;
	}
	return int(c);
}
lli con(char ch[], int i, int j)
{
	lli s=0;
	for(int k=i;k<=j;k++)
		s = s*10 + (ch[k] - '0');
	return s;
}
char ch[500];
lli ar[30];
int main()
{
	int t; getNum(t);
	while(t--)
	{
		int a;
		getNum(a);getStr(ch);
		if(a==0 || (strlen(ch)==1 && ch[0] == '0'))
		{
			printf("0\n");continue;
		}
		int p = strlen(ch);
		int l = (p-1)/10;
		for(int i=0; i<=l; i++)
		{
			if(p<=10)
				ar[i] = con(ch,0,p-1);
			else
				ar[i] = con(ch,p-10,p-1);
			p-=10;
		}
		printf("%d\n",gcd(a,cmp_mod(ar,l,a)));
	}
	return 0;
}
