#include <bits/stdc++.h>

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)
#define getStr(st) scanf("%s",st)

using namespace std;

struct mystring 
{
	char ch[13];
};

mystring ar[5200];
// int ar[5200];

//returns true if a<b
bool compare(const mystring& a, const mystring& b)
{
	int l1 = strlen(a.ch), l2 = strlen(b.ch);
	int m = min(l1,l2);
	f(i,m)
	{
		if(a.ch[i]<b.ch[i])
			return true;
		else if(a.ch[i]>b.ch[i])
			return false;
	}
	return false;
}
bool compare1(const mystring& a, char ch[13])
{
	int l1 = strlen(a.ch), l2 = strlen(ch);
	int m = min(l1,l2);
	f(i,m)
	{
		if(a.ch[i]<ch[i])
			return true;
		else if(a.ch[i]>ch[i])
			return false;
	}
	return false;
}
int compute(char ch[13])
{
	int l = strlen(ch);
	int sum=0;
	f(i,l)
		sum+=(ch[i]-'A'+1);
	return sum;
}

int search(int l, int r, char ch[13])
{
	int mid = (l+r)/2;
	if(strcmp(ch,ar[mid].ch)==0)
		return mid+1;
	else if(mid==l && l==r)
		return 0;
	else if(compare1(ar[mid],ch))
		return search(mid+1,r,ch);
	else
		return search(l,mid-1,ch);
}

int main()
{
	int n,q;
	getNum(n);
	f(i,n)
		getStr(ar[i].ch);
	getNum(q);
	sort(ar,ar+n,compare);
	// f(i,n)
	// 	printf("%s\n",ar[i].ch);
	while(q--)
	{
		char ch[13];
		getStr(ch);
		int ret = compute(ch)*(search(0,n-1,ch));
		printf("%d\n",ret);
	}
	return 0;
}