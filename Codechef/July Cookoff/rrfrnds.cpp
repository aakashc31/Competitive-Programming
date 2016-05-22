#include <cstdio>
#include <bitset>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)
typedef long long int lli;

char graph[2000][2000];

bool can_be_connected(int i, int j, int n)
{
	bool flag = false;
	f(k,n)
	{
		if(graph[i][k] == '1' && graph[j][k]=='1')
			return true;
	}
	return flag;
}
int main()
{
	int n;
	getNum(n);
	f(i,n)
	{
		scanf("%s",graph[i]);
	}
	// 
	int num_con = 0;
	f(i,n)
	{
		for(int j=i+1; j<n;j++)
		{
			if(graph[i][j]=='0')
			{
				if(can_be_connected(i,j,n))
					num_con++;
			}
		}
	}
	printf("%d\n",2*num_con);
	return 0;
}

