#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)

int ar[5][101];
int mycnt[5];
int main()
{
	f(i,5)
	{
		mycnt[i]=0;
		f(j,101) ar[i][j]=0;
	}

	int n;
	scanf("%d",&n);
	f(i,n)
	{
		char ch; int m;
		cin>>ch>>m;
		ar[ch-'A'][m]++;
		mycnt[ch-'A']++;
	}	

	f(i,5)
	{
		bool flag = false;
		f(m,101)
		{
			int perc = 0;
			if(ar[i][m]*10 > mycnt[i])
			{
				printf("%d ",m);
				flag = true;
			}
		}
		if(!flag)
			printf("Nothing Unusual");
		printf("\n");
	}
	return 0;
}