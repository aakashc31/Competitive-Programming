#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(lli i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked


typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

lli ar[33000];
lli ans[15];
bool flag[33000];
int main()
{
	lli t,n,nsubsets,numTrue,next,index,sum,k;
	gl(t);
	while(t--)
	{
		gl(n);
		nsubsets = (1<<n);
		f(i,nsubsets) 
		{
			gl(ar[i]);
			flag[i] = false;
		}
		flag[0] = true;
		numTrue = 1;
		next = 0;
		index = 0;
		sort(ar,ar + nsubsets);
		while(true)
		{
			while(flag[next]) next++;
			ans[index++] = ar[next];
			if(index == n)
				break;
			f(i,(1<<(index-1)))
			{
				//i is the mask
				sum = ans[index-1];
				f(j,index)
				{
					if(i&&(1<<j))
						sum+=ans[j];
				}
				k = next;
				while(k < nsubsets)
				{
					if(ar[k]==sum && flag[k]==false)
					{
						flag[k]=true;
						break;
					}
					k++;
				}
			}
		}
		f(i,index) printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}