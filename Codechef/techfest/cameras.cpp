#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
#define mp make_pair
typedef pair<int,int> pii;
bool comp(const pii& a, const pii& b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
pii interval[100000];
int cams[100000];
int make_disjoint(int k)
{
	pii ar[100000];
	ar[0] = interval[0];
	int ind = 1;
	for(int i=1; i<k; i++)
	{
		if(interval[i].first <= ar[ind-1].second)
			ar[ind-1].second = max(interval[i].second,ar[ind-1].second);
		else
		{
			ar[ind++] = interval[i];
			// ind++;
		}
	}
	f(i,ind) interval[i] = ar[i];
	return ind;
}
int main()
{
	int n,k,a,b;
	g(n),g(k);
	f(i,n) g(cams[i]);
	sort(cams,cams+n);
	f(i,k)
	{
		g(a),g(b);
		interval[i]=mp(min(a,b),max(a,b));
	}
	sort(interval,interval+k,comp);
	k = make_disjoint(k);
	int i=0,j=0,cnt=0;
	while(i<n && j<k)
	{
		if(cams[i]>= interval[j].first && cams[i] <= interval[j].second)
		{
			cnt++;
			i++;
		}
		else if(cams[i] < interval[j].first)
			i++;
		else
			j++;
	}
	printf("%d\n",cnt);
	return 0;
}