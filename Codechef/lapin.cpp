#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int t;
	getNum(t);
	while(t-- > 0)
	{
		int ar[26];
		f(i,26)
			ar[i] = 0;
		char ch[1000];
		scanf("%s",ch);
		int l = strlen(ch);
		int offset = l%2;
		int mid = (l/2)-1;
		f(i,mid+1)
		{
			ar[ch[i]-97]++;
			ar[ch[mid+1+i+offset]-97]--;
			
		}
		bool t = true;
		f(i,26)
		{
			if(ar[i]!=0)
			{
				t=false;
				break;
			}
		}
		if(t)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}
	return 0;
}