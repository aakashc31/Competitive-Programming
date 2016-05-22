#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
void rotate(char ch[5], int l)
{
	char c = ch[0];
	for(int j=l-1; j>=0;j--)
	{
		char temp = ch[j];
		ch[j] = c;
		c = temp;
	}
}

int toInt(char ch[5], int i, int j)
{
	int r=0;
	for(int k=i;k<=j;k++)
	{
		r = r*10 + (ch[k]-'0');
	}
	return r;
}

void create_all_circular_perm(char a[5], int ar[12])
{
	int l = strlen(a);
	f(i,l)
	{
		ar[i] = toInt(a,0,l-1);
		rotate(a,l);
	}
	int p=12/l;
	int offset = l;
	f(i,p-1)
	{
		f(j,l)
		{
			ar[offset+j] = ar[j];
		}
		offset+=l;
	}
}
void toCharArray(char ch[5], int num)
{
	int i=0;
	while(num>0)
	{
		ch[i] = (num%10)+'0'; num/=10; i++;
	}
	int j=0;i--;
	while(j<=i)
	{
		char c = ch[i];
		ch[i] = ch[j];
		ch[j] = c;
		i--,j++;
	}
}
int main()
{
	printf("1\n10\n");
	f(i,10)
	{
		f(j,100)
			printf("%d ",j+1);
		printf("\n");
	}
	return 0;
}