#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
int ar[100005];
int main()
{
	int n,m;
	g(n),g(m);
	f(i,n) g(ar[i]);
	int clk = 0, ant_clk=0;
	char choice; int val,index,net;
	while(m--)
	{
		cin >> choice;
		g(val);
		if(choice == 'C')
			clk+=val;
		else if(choice == 'A')
			ant_clk+=val;
		else
		{
			val--;
			net = ((clk%n)-(ant_clk%n));
			if(net==0)
				index = val;
			else if(net>0)
				index = (val+net)%n;
			else
			{
				index = (val+net);
				if(index<0)
					index+=n;
			}
			printf("%d\n",ar[index]);
		}
	}
	return 0;
}