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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;


int main()
{
	ll answers[3001];
	
	memset(answers, 0 , sizeof(answers));
	int N = 3000;
	for(int r = 1; r*r <= N; r++)
	{
		for(int s = 1; s < r; s++)
		{
			int c = r*r + s*s;
			int b = r*r - s*s;
			int a = 2*r*s;
			int p = a*b*c;
			int sum = a+b+c;
			if(sum > N)
				continue;
			if(p > answers[sum])
				answers[sum] = p;

			for(int d = 2; d*sum <= N; d++)
			{
				ll newS = d*sum;
				ll newP = d*d*d*p;

				if(newS <= N)
				{
					if(newP > answers[newS])
						answers[newS] = newP;
				}

			}
		}
	}

	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(answers[n] > 0)
			cout << answers[n] << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}