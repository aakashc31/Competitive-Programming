#include <bits/stdc++.h>

using namespace std;

#define getcx getchar//_unlocked
// #define get(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

inline void get( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int c[401];
int last_order_index[401];
int tables[200];
int next_order[200];
int order[400];
int main()
{
	int t,n,m,temp;
	get(t);
	while(t--)
	{
		f(i,401) c[i]=0,last_order_index[i]=-1;
		f(i,200) tables[i] = 0;

		get(n); //num tables
		get(m);
		f(i,m)
		{
			get(temp);
			order[i]=temp;
			c[temp]++;
		}
		int clean = 0, occupied = 0;
		f(i,m)
		{
			int next = order[i];
			bool flag=false;
			f(j,n)
			{
				if(tables[j]==next)
				{
					flag = true;
					break;
				}
			}
			if(flag) //means that next already has a table
			{
				c[next]--;
				continue;
			}
			if(occupied<n) //means that he does not have a table but there is an empty table
			{
				tables[occupied]=next;
				c[next]--;
				clean++;
				occupied++;
			}
			else //there is no empty table
			{
				bool flag = false;
				f(j,n) //if there is customer who has no future orders
				{
					if(c[tables[j]]==0)
					{
						tables[j]=next;
						c[next]--;
						clean++;
						flag=true;
						break;
					}
				}
				if(flag)
					continue;
				// now the one who has the last next order has to leave
				int leaving = 0, index=-1;
				f(j,n)
				{
					int ord=-1;
					for(int k=i+1;k<m;k++)
					{
						if(order[k]==tables[j])
						{
							ord=k;
							break;
						}
					}
					if(ord>leaving)
					{
						leaving=ord;
						index=j;
					}
				}
				// we have index who will leave the table
				tables[index] = next;
				c[next]--;
				clean++;
			}
		}

		printf("%d\n",clean);
	}

	return 0;
}