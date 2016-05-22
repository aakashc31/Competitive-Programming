#include <bits/stdc++.h>
using namespace std;


typedef long long int lli;
typedef pair<lli,lli> pii;
#define f(i,n) for(lli i=0; i<n; i++)
#define g(n) scanf("%lld",&n)
lli ar[100000];
pii diff[100000];
map<pii,lli> counts;

bool comparator(const pii& a, const pii& b)
{
	return a.first < b.first;
}

// makes the difference of ar[i] & ar[i+1] the c.d. of the A.P
bool isBeautiful(lli f, lli cd, lli n, lli k)
{
	lli num_changes = 0;
	f(j,n)
	{
		if(ar[j] != (f+cd*j))
			num_changes++;
	}
	// printf("%d %d \n",i,num_changes);
	return (num_changes<=k);
}

int main()
{
	lli n,k;
	g(n), g(k);
	f(i,n) g(ar[i]);
	lli f_ans=0, d_ans = 0, kmax = 0;
	bool first_loop = true;
	if(n<=100)
	{
		f(i,n-1)
		{
			for(lli j=i+1;j<n;j++)
			{
				lli d = ar[j] - ar[i];
				if(d%(j-i)!=0)
					continue;
				d = d/(j-i);
				lli f = ar[i]-d*i;
				if(isBeautiful(f,d,n,k))
				{
					if(!first_loop)
					{
						if(f < f_ans)
							f_ans = f, d_ans = d;
						else if(f==f_ans && d<d_ans)
							d=d_ans;
					}
					else
					{
						f_ans = f, d_ans = d;
						first_loop = false;
					}
				}
			}
		}

		f(i,n)
			printf("%lld ",f_ans+i*d_ans);
		printf("\n");
	}
	else
	{
		f(i,n-1)
		{
			lli d = ar[i+1]-ar[i];
			lli f = ar[i] - i*d;
			pii temp = make_pair(f,d);
			if(counts.find(temp)!=counts.end())
			{
				lli k = counts[temp] = counts.find(temp)->second + 1;
				if(k>kmax)
				{
					kmax = k;
					f_ans = f;
					d_ans = d;
				}
			}
			else
				counts[temp] = 1;
		}
		f(i,n)
			printf("%lld ",f_ans+i*d_ans);
		printf("\n");
	}
	return 0;
}