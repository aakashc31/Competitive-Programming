#include<stdio.h>
 
int main()
{
	int t,n,i,k;
	char s[1001];
	scanf("%d",&t);
	while(t--)
	{
		k=0;
		scanf("%d",&n);
		scanf("%s",&s);
		
	if(s[0]=='0')
	{
		if(n>1)
		{if(s[1]=='0')
				k++;
		}
		else
		{
			k++;
		}
	}
		for(i=1;i<=n-2;i++)
			{if(s[i]=='0')
			{	if(s[i-1]=='0' && s[i+1]=='0')
			       k++;
		 
		}}
			if(s[n-2]=='0' && s[n-1]=='0')
				k++;
 
	printf("%d\n",k);
	}
	return 0;
} 