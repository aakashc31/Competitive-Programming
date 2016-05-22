#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)

pii ar[100000];
bitset<100000> vis;
int set_temp[100000];
bool comp(const pii& a, const pii& b)
{
	return a.first < b.first;
}
int search(int beg, int end, int s)
{
	// printf("Yo %d, %d s = %d\n",beg,end,s);
	int len = end-beg+1;
	if(len==0)
		return -1;
	if(len==1)
	{
		 if(s==ar[beg].first && !vis[beg])
		 	return beg;
		 else
		 	return -1;
	}
	int mid = (beg+end)/2;
	if(ar[mid].first==s)
	{
		if(vis[mid])
		{
			int i1 = search(beg,mid-1,s);
			int i2 = search(mid+1,end,s);
			if(i1!=-1)
				return i1;
			if(i2!=-1)
				return i2;
			return -1;
		}
		else
			return mid;
	}
	else if(ar[mid].first < s)
		return search(mid+1,end,s);
	else
		return search(beg,mid-1,s);
}

int main()
{
	vis.set();
	vis.flip();
	int n,a,b,temp;
	g(n), g(a), g(b);
	f(i,n) 
	{
		g(temp);
		ar[i] = make_pair(temp,i);
	}
	sort(ar,ar+n,comp);
	int i = 0;
	bool flag = false;
	while(i < n)
	{
		if(vis[i])
		{
			i++;
			continue;
		}
		vis[i] = 1;
		int index = search(0,n-1,a-ar[i].first);
		if(index!=-1)
		{
			// printf("Found unvis at %d for %d\n",index,ar[i]);
			vis[index] = 1;
			set_temp[ar[i].second] = set_temp[ar[index].second] = 0;
			i++;
			continue;
		}
		index = search(0,n-1,b-ar[i].first);
		if(index!=-1)
		{
			// printf("@Found unvis at %d for %d\n",index,ar[i]);
			vis[index] = 1;
			set_temp[ar[i].second] = set_temp[ar[index].second] = 1;
			i++;
			continue;
		}
		else
		{
			flag = true;
			break;
		}
	}

	if(flag)
		printf("NO\n");
	else
	{
		printf("YES\n");
		f(i,n) printf("%d ",set_temp[i]);
	}
}