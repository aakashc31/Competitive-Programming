#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> pii;

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)

pii ar[100];
bool fcompare(const pii& a, const pii& b)
{
	return a.first < b.first;
}
bool scompare(const pii& a, const pii& b)
{
	return a.second < b.second;
}
int main()
{
	int n,m;
	getNum(n), getNum(m);
	f(i,n)
	{
		int temp; getNum(temp);
		ar[i].first = i, ar[i].second = ceil((float(temp))/m);
	}
	stable_sort(ar, ar+n, scompare);
	printf("%d\n",ar[n-1].first+1);
	return 0;
}