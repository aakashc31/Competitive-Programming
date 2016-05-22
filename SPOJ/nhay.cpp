#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

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
	int m; 
	while(cin >> m)
	{
		char* patt = new char[m+5];
		scanf("%s",patt);
		int *ar = create_auxiliary_func(patt,m);
		int j=0,i=0;
		char ch;
		getcx();
		ch = getcx();
		while(ch!='\n')
		{
			if(ch==patt[j])
			{
				j++;
				i++;
				// cin>>ch;
				ch = getcx();
			}
			if(j==m)
			{
				printf("%d\n",i-m);
				j = ar[j-1];
			}
			else if(ch!=patt[j])
			{
				if(j==0)
				{
					// cin>>ch;
					ch = getcx();
					i++;
				}
				else
				{
					j = ar[j-1];
					// i = i-j+1;
				}
			}
		}
		printf("\n");
	}
	return 0;
}