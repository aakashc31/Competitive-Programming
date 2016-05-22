#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define g(n) scanf("%lld",&n)
// #define g(n) inp(n)
#define f(i,n) for(lli i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(lli i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked


typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

lli count_inversions(lli ar[], lli left, lli right)
{
	// base case
	if(left==right)
		return 0;
	lli mid = (left+right)/2;

	lli l = count_inversions(ar,left, mid);
	lli r = count_inversions(ar,mid+1, right);
	lli s = 0;
	lli i=left, j=mid+1;
	lli new_ar[right-left+1];
	lli n_ind = 0;
	while(i<=mid || j<=right)
	{
		if(i>mid)
		{
			while(j<=right)
			{
				new_ar[n_ind] = ar[j];
				j++;
				n_ind++;
			}
			break;
		}

		if(j>right)
		{
			while(i<=mid)
			{
				new_ar[n_ind] = ar[i];
				i++;
				n_ind++;
			}
			break;
		}

		if(ar[i] <= ar[j])
		{
			new_ar[n_ind++] = ar[i++];
		}
		else
		{
			new_ar[n_ind++] = ar[j];
			s+=(mid-i+1);
			j++;
		}
	}

	f(i,right-left+1)
		ar[left+i] = new_ar[i];
	s+=(l+r);
	return s;
}
bool isSame(lli* ar, lli len)
{
	if(len<=1)
		return false;
	// lli prev = ar[0];
	fab(i,1,len-1)
	{
		if(ar[i]==ar[i-1])
		{
			return true;
		}
	}
	return false;
}
lli ar[100000];
int main()
{
	lli t,n,k;
	g(t);
	lli num = 1;
	while(t--)
	{
		g(n);
		g(k);
		f(i,n) g(ar[i]);
		lli inv = count_inversions(ar,0,n-1);
		if(inv >= k)
		{
			printf("Case %lld: %lld\n",num,inv-k);
		}
		else
		{
			if(isSame(ar,n))
				printf("Case %lld: 0\n",num);
			else
				printf("Case %lld: %lld\n",num,(k-inv)%2);
		}
		num++;
	}
	return 0;
}