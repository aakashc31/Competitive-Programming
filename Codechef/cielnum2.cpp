// chutiya problem
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)



int main()
{
	int n=0;
	char num[100];
	gets(num);
	int len = strlen(num);
	f(i,len)
	{
		if(num[i]>='0' && num[i]<='9')
		{
			n = n*10 + (num[i]-'0');
		}
		else if(num[i]!=' ')
			break;
	}
	int s=0;
	while(n--)
	{
		char ch[110];
		gets(ch);
		int l = strlen(ch);
		// cout << l <<endl;
		int j = l-1;
		bool flag = false;
		int d1=0,d2=0,d3=0;
		while(ch[j]==' ')
			j--;
		while(ch[j]!=' ')
		{
			if(ch[j]=='8')
				d1++;
			else if(ch[j]=='5')
				d2++;
			else if(ch[j]=='3')
				d3++;
			else
			{
				flag = true;
				break;
			}
			j--;
		}
		if(!flag && d1>=d2 && d2>=d3)
			s++;
	}
	printf("%d\n",s );
	return 0;
}