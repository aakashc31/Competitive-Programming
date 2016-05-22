#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)

char ch[1001];

int find_kmax(int k)
{
	int max = 1;
	int l = strlen(ch);
	f(i,k)
		max *= (ch[i]-'0');
	int p = max;
	for(int i=k; i<l; i++)
	{
		int temp = (ch[i-k]-'0');
		if(temp!=0)
			p = (p*(ch[i]-'0'))/temp;
		else
		{
			p = 1;
			f(j,k)
				p *= (ch[i-k+1+j]-'0');
		}
		if(p > max)
			max = p;
	}
	return max;
}


int main()
{
	int t,n,k;
	getNum(t);
	while(t--)
	{
		getNum(n), getNum(k);
		scanf("%s",ch);
		printf("%d\n",find_kmax(k));
	}
	return 0;
}