#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
// #define get(n) scanf("%d",&n)

inline void get( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

char ch[100001];

int main()
{
	int t,i,j;
	get(t);
	while(t--)
	{
		scanf("%s",ch);
		i=0;
		j = strlen(ch)-1;
		bool flag = true;
		while(i<=j)
		{
			if(ch[i]!=ch[j])
			{
				flag = false;
				break;
			}
			i++,j--;
		}
		if(flag)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}