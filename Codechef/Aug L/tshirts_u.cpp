#include <bits/stdc++.h>

#define f(i,n) for(int i=0;i<n;i++)
#define get(n) scanf("%d",&n)

typedef long long int lli;

using namespace std;

int ar[10];
int index_temp=0;
int n;
const int modulo = 1000000007;
int shirts[1000][100];
char ch[350];
int pi[100];
int abs(int n)
{
	if(n<0)
		return -n;
	return n;
}
int LUP_Decompose()
{
	f(i,100)
		pi[i]=i;
	f(k,100)
	{
		int p=0, kp = k;
		for(int i=k+1;i<100;i++)
		{
			if(abs(shirts[i][k])>p)
			{
				p=abs(shirts[i][k]);
				kp = i;
			}
		}
		swap(pi[k],pi[kp]);
		f(i,100)
		{
			swap(shirts[k][i],shirts[kp][i]);
		}
		for(int i=k+1; i<100;i++)
		{
			for(int j=k+1;j<100;j++)
			{
				shirts[i][k] = shirts[i][k]/shirts[k][k];
				shirts[i][j] -= shirts[i][k]*shirts[k][j];
			}
		}
	}
	int p=1;
	f(k,100)
	{
		p = (p*shirts[k][k])%modulo;
	}
	return p;
}

int main()
{
	int t;
	get(t);
	while(t--)
	{
		get(n);
		f(i,n)
		{
			f(j,100) shirts[i][j]=0;
		}
		getchar();
		f(i,n)
		{
			gets(ch);
			int j=0;
			int temp = 0;
			while(ch[j]!='\0')
			{
				if(ch[j]==' ')
				{
					shirts[i][temp-1]=1;
					temp = 0;
				}
				else 
				{
					temp = temp*10 + (ch[j]-'0');
				}
				j++;
			}
			if(ch[j-1]!=' ')
				shirts[i][temp-1]=1;
		}
		for(int i=n;i<100;i++)
		{
			for(int j=0;j<n;j++)
			{
				shirts[i][j]=-1;
			}
		}
		for(int j=1;j<n;j++)
		{
			for(int i=99;i>=100-j;i--)
				shirts[i][j]=0;
		}
		for(int i=n;i<100;i++)
		{
			for(int j=n;j<100;j++)
			{
				if(i==j)
					shirts[i][j]=1;
				else
					shirts[i][j]=0;
			}
		}
		f(i,10)
		{
			f(j,100)
				printf("%d ",shirts[i][j]);
			printf("\n");
		}
		printf("%d\n",LUP_Decompose());
	}
	return 0;
}