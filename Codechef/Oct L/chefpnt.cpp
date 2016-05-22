#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define g(n) scanf("%d",&n)
typedef pair<int,int> pii;

vector<pair<pii,bool> > steps;
bool ar[100][100];
pair<pii,bool> getNextStep(int n, int m)
{
	pii up = mp(-1,-1);
	pii left = mp(-1,-1);
	int curr_up = 0, curr_left = 0;
	int max_left = 0, max_up = 0;
	f(i,n)
	{
		curr_left = 0;
		f(j,m)
		{
			if(ar[i][j]) //if (i,j) is painted
			{
				curr_left = 0;
			}
			else
			{
				curr_left++;
				if(curr_left >= max_left)
				{
					max_left = curr_left;
					left = mp(i,j);
				}
			}
		}
	}

	f(j,m)
	{
		curr_up = 0;
		f(i,n)
		{
			if(ar[i][j])
			{
				curr_up = 0;
			}
			else
			{
				curr_up++;
				if(curr_up >= max_up)
				{
					max_up = curr_up;
					up = mp(i,j);
				}
			}
		}
	}
	// printf("Up - %d %d, max_up = %d\nLeft - %d %d, max_left = %d\n",up.first,up.second,max_up,left.first,left.second,max_left);
	if(max_up==0 && max_left==0)
		return mp(up,false);
	if(max_left > max_up)
		return mp(left,false);
	else
		return mp(up,true);
}

int main()
{
	int n,m,k,a,b;
	f(i,n){f(j,m) ar[i][j]=false;}
	g(n),g(m),g(k);
	f(i,k)
	{
		g(a),g(b);
		a--,b--;
		ar[a][b] = true;
	}
	
	pair<pii,bool> step = getNextStep(n,m);

	while(step.first.first != -1)
	{
		int i,j;
		steps.pb(step);
		if(step.second) //go up
		{
			i = step.first.first;
			j = step.first.second;
			while(ar[i][j]==false && i>=0)
			{
				ar[i][j] = true;
				i--;
			}
		}
		else
		{
			i = step.first.first;
			j = step.first.second;
			while(ar[i][j]==false && j>=0)
			{
				ar[i][j] = true;
				j--;
			}
		}
		step = getNextStep(n,m);
	}
	printf("%d\n",steps.size());
	f(i,steps.size())
	{
		if(steps[i].second)
		{
			printf("%d %d 1\n",steps[i].first.first + 1,steps[i].first.second + 1);
		}
		else
			printf("%d %d 0\n",steps[i].first.first + 1,steps[i].first.second + 1);
	}
	return 0;
}