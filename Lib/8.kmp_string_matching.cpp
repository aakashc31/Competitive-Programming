#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)
#define getStr(st) scanf("%s",st)

int* create_auxiliary_func(char ch[], int );
void matchKMP(char text[],int n, char patt[], int m)
{
	int *ar = create_auxiliary_func(patt,m);
	int i=0,j=0;
	while(i<n)
	{
		if(text[i]==patt[j])
		{
			i++,j++;
		}
		if(j==m)
		{
			printf("Pattern matched at %d in text\n",i-m);
			j = ar[j-1];
		}
		else if(text[i]!=patt[j])
		{
			if(j==0)
				i++;
			else
			{
				j = ar[j-1];
				// i = i-j+1;
			}
		}
	}
}

int* create_auxiliary_func(char ch[],int m)
{
	int* aux = new int[m];
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
	return aux;
}

int main()
{
	char ch[] = "aa";
	// int* t = create_auxiliary_func(ch,2);
	// f(i,2)
	// 	printf("%d ",t[i]);
	// printf("\n");
	char tt[] = "aakashaaakash";
	matchKMP(tt,13,ch,2);
	return 0;
}