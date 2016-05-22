#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int t;
	getNum(t);
	//fflush(stdin); //here i was using fflush(stdin), this would have cleared the entire input stream.
	getchar();
	while(t-- > 0)
	{
		char ch[111];
		gets(ch);
		int l = strlen(ch);
		bool flag = false;
		if(l==5 && ch[0]>='a' && ch[0]<='h' && ch[3]>='a' && ch[3]<='h' && ch[1]>='1' &&ch[1]<='8'&&ch[4]>='1'&&ch[4]<='8'&& ch[2]=='-')
		{
			flag = true;
		}
		if(!flag)
			printf("Error\n");
		else
		{
			int a = ch[0]-ch[3];
			int b = ch[1]-ch[4];
			int xdif = (a>0)?a:-a;
			int ydif = (b>0)?b:-b;
			if((xdif==1 && ydif==2) || (xdif==2 && ydif==1))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}