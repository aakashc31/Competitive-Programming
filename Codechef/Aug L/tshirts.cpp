#include <bits/stdc++.h>

using namespace std;

#define get(n) scanf("%lld",&n)//getchar//_unlocked
#define f(i,n) for(lli i=0; i<n; i++)

typedef long long int lli;

// inline void get( int &n )//fast input function
// {
// 	n=0;
// 	int ch=getcx();int sign=1;
// 	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
// 	while( ch >= '0' && ch <= '9' )
// 	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
// 	n=n*sign;
// }

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int, int> pii;

const lli modulo = 1000000007;


char ch[350];
lli dp[10][100];
lli num_shirts[10];
int main()
{
	lli t,n;
	get(t);
	while(t--)
	{
		get(n);
		f(i,n)
		{
			f(j,100) dp[i][j]=0;
			num_shirts[i]=0;
		}
		getchar();
		f(i,n)
		{
			gets(ch);
			lli j=0;
			lli temp = 0;
			while(ch[j]!='\0')
			{
				if(ch[j]==' ')
				{
					dp[i][temp-1]=1;
					temp = 0;
					num_shirts[i]++;
				}
				else 
				{
					temp = temp*10 + (ch[j]-'0');
				}
				j++;
			}
			dp[i][temp-1]=1;
			num_shirts[i]++;
		}
		// input over
		//fill the matrix dp
		// base case
		f(i,100)
		{
			if(dp[0][i]==1)
				dp[0][i] = num_shirts[0]-1;
			else
				dp[0][i] = num_shirts[0];
		}

		// induction
		for(lli i=1; i<n-1; i++)
		{
			f(j,100)
			{
				if(dp[i][j]==0)
				{
					dp[i][j] = (num_shirts[i]*dp[i-1][j])%modulo;
				}
				else
				{
					dp[i][j] = ((num_shirts[i]-1)*dp[i-1][j])%modulo;
				}
			}
		}

		lli ans = 0;
		f(j,100)
		{
			if(dp[n-1][j]==1)
			{
				ans= (ans+dp[n-2][j])%modulo;
			}
		}

		printf("%d\n",ans);

		

	}
	return 0;
}




// testing input
		// f(i,n)
		// {
		// 	printf("%d -> ",i+1);
		// 	for(int j=1;j<=shirts[i][0];j++)
		// 	{
		// 		printf("%d ",shirts[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// correct