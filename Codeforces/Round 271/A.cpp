#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
char a1[] = "qwertyuiop";
char a2[] = "asdfghjkl;";
char a3[] = "zxcvbnm,./";

int find(char* c, char ch)
{
	f(i,strlen(c)){
		if(ch==c[i]){
			return i;
		}
	}
	return -1;
}

int main()
{
	char ch;
	char ar[101];
	scanf("%c",&ch);
	scanf("%s",ar);
	int off;
	if(ch=='L')
		off = 1;
	else
		off = -1;
	f(i,strlen(ar)){
		int ind = find(a1,ar[i]);
		if(ind!=-1){
			ar[i] = a1[ind+off];
		}
		else
		{
			ind = find(a2,ar[i]);
			if(ind!=-1)
			{
				ar[i] = a2[ind+off];
			}
			else
				ar[i] = a3[find(a3,ar[i])+off];
		}
	}
	printf("%s\n",ar);
	return 0;
}