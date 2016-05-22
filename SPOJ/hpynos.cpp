#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
int happy[811];
int break_number(int n)
{
	int s=0;
	while(n>0)
	{
		int d = n%10;
		s += d*d;
		n/=10;
	}
	return s;
}

// n<=810 
int isHappy(int n)
{
	if(n==1) return 0;
	bitset<811> visited;
	visited.set(), visited.flip();
	int t=0;
	while(!visited[n])
	{
		visited[n] = 1;
		if(n==1)
			return t;
		n = break_number(n);
		t++;
	}
	return -1;
}

void init()
{
	f(i,811) 
		happy[i] = isHappy(i);
}

int main()
{
	init();
	// cout << happy[13] <<endl<<happy[7]<<endl;
	int n;
	g(n);
	int s = break_number(n);
	if(happy[s]==-1)
		printf("-1\n");
	else
		printf("%d\n",happy[s]+1);
	return 0;
}