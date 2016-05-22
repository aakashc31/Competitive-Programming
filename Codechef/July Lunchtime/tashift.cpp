#include <bits/stdc++.h>

using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar_unlocked
typedef long long int lli;

char a[1000000];
char b[1000000];

void input_a()
{
	int i=0;
	char ch = getcx();
	while(!(ch>='a' && ch<='z')) ch = getcx();
	while(ch>='a' && ch<='z')
	{
		a[i++] = ch;
		ch = getcx();
	}
	a[i] = '\0';
}
void input_b()
{
	int i=0;
	char ch = getcx();
	while(!(ch>='a' && ch<='z')) ch = getcx();
	while(ch>='a' && ch<='z')
	{
		b[i++] = ch;
		ch = getcx();
	}
	b[i] = '\0';
}

inline void inp( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
int main()
{
	int n;
	inp(n);
	input_a();
	input_b();
	// getcx();
	// f(i,n)
	// 	a[i] = getcx();
	// // printf("%s\n",a );
	// getcx();
	// f(i,n)
	// 	b[i] = getcx();
	int lcp_max = 0;
	int index = 0;
	int i = 0;
	for(i=0; i<n; i++)
	{
		bool flag= true;
		int temp = 0;
		int j=i, aind = j-i;
		while(true)
		{
			if(a[aind++]==b[j])
			{
				temp++;
				j++;
			}
			else
			{
				flag = false;
				break;
			}
			if(j>=n)
				j=0;
			if(j==i)
				break;
		}
		if(flag)
		{
			lcp_max = n;
			index = i;
			break;
		}
		else
		{
			if(temp > lcp_max)
			{
				lcp_max = temp;
				index = i;
			}
		}
	}
	printf("%d\n",index);
	return 0;
}