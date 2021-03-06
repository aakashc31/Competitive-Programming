#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

inline int inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

const int modulo = 1000000007;

int shirts[10][105];
char ch[350];
ll dp[1025][109];
int n;

//dp[mask][i] = number of ways of alloting shirts to subset rep by mask using only first i shirts

ll compute(int mask, int i){
	if(i == 101){
		if(mask == ((1<<n)-1)){
			dp[mask][i] = 1;
			return 1;
		}
		else{
			dp[mask][i] = 0;
			return 0;
		}

	}
	if(dp[mask][i] != -1)
		return dp[mask][i];
	ll ans = compute(mask, i+1); //do not give ith tshirt to anyone
	for(int j = 0; j < n; j++){
		if(mask & (1<<j)) //this means jth person already has a tshirt
			continue;
		if(shirts[j][i] == 0) //if jth person does not have ith shirt
			continue;
		ans += compute(mask | (1<<j), i+1);
		ans %= modulo;
	}

	dp[mask][i] = ans;
	return ans;

}


int main()
{
	int t = inp();
	while(t--)
	{	
		memset(dp, 0xff, 1025*109*8);
		n = inp();
		// cout << "n = " << n << endl;
		f(i,n)
		{
			f(j,101) shirts[i][j]=0;
		}
		f(i,n)
		{
			gets(ch);
			// cout << "line = " << ch << endl;
			int j=0;
			int temp = 0;
			while(ch[j]!='\0')
			{
				if(ch[j]==' ')
				{
					// cout << "got " << temp << endl;
					shirts[i][temp]=1;
					temp = 0;
				}
				else 
				{
					temp = temp*10 + (ch[j]-'0');
				}
				j++;
			}
			if(ch[j-1]!=' '){
				// cout << "got " << temp << endl;
				shirts[i][temp]=1;
			}
		}
		cout << compute(0,1) << endl;
	}
	return 0;
}