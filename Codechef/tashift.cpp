#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)
#define getStr(st) scanf("%s",st)
char a[1000010];
char b[2000010];
int aux[1000000];
void create_auxiliary_func(int m)
{
	char* ch = a;
	aux[0] = 0;
	int i=1;
	int len=0;
	while(i<m)
	{
		if(ch[i] == ch[len])
		{
			aux[i] = len+1;
			i++;
			len++;
		}
		else
		{
			if(len==0)
			{
				aux[i]=0;
				i++;
			}
			else
			{
				len = aux[len-1];
			}
		}
	}
}

int matchKMP(int n)
{
	create_auxiliary_func(n);

	int* ar = aux;
	int ret = 0, ind = -1;
	int i=0,j=0;
	char* text = b;
	char* patt = a;
	while(i<2*n)
	{
		if(text[i]==patt[j])
		{
			i++,j++;
		}
		if(j==n)
		{
			return i-j;
			// printf("Pattern matched at %d in text\n",i-m);
			// j = ar[j-1];
		}
		else if(text[i]!=patt[j])
		{
			if(j==0)
				i++;
			else
			{
				if(j>ret)
				{
					ret = j;
					ind = i-j;
				}
				j = ar[j-1];
			}
		}
	}
	if(ind==-1)
		return 0;
	// printf("%d\n",ret);
	return ind;
}





int main()
{
	int n;
	getNum(n);
	getStr(a);
	getStr(b);
	f(i,n)
		b[i+n] = b[i];
	b[2*n]='\0';
	printf("%d\n",matchKMP(n));
	return 0;
}