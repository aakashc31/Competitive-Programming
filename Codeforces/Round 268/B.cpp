#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
pii X[50], Y[50];
int p,q,l,r;

int number_inter(int a, int b, int c, int d, int t)
{
	if(c>b)
		return 0;
	if(d<a)
		t-=(a-d);
	if(t<0)
		return 0;
	c += (a-d);
	d=a;
	if(t>=b-c)
		return 1+b-c;
	else
		return 1+t;
}

bool isInter(int a, int b, int c, int d, int t)
{
	c+=t, d+=t;
	if(d<a || c>b)
		return false;
	return true;
}

int main()
{
	g(p), g(q), g(l), g(r);
	int a,b;
	f(i,p)
	{
		g(a),g(b);
		X[i] = make_pair(a,b);
	}
	f(i,q)
	{
		g(a),g(b);
		Y[i] = make_pair(a,b);
	}
	int ans = 0;
	for(int t=l;t<=r;t++)
	{
		bool flag = false;
		f(i,p)
		{
			f(j,q)
			{
				if(isInter(X[i].first, X[i].second, Y[j].first, Y[j].second,t))
				{
					// printf("True for %d,%d %d,%d at %d\n",X[i].first, X[i].second, Y[j].first, Y[j].second,t);
					flag = true;
					ans++;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	printf("%d\n",ans);
	return 0;
}