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

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;


char *ch;

bool unit_distance(char* a, char* b)
{
	int l = strlen(a); //|b| = l+1
	bool flag = true;
	f(i,l)
	{
		if(flag)
		{
			if(a[i]!=b[i])
				flag = false;
		}
		else
		{
			if(a[i]!=b[i+1])
				return false;
		}
	}
	return true;
}

int main()
{
	ch = new char[100005];
	int t;
	g(t);
	test(t)
	{
		scanf("%s", ch);
		int l = strlen(ch);
		bool ans = false;
		if(l&1)
		{
			char* temp = new char[l/2+1];
			f(i, l/2)
				temp[i] = ch[l/2 - 1 - i];
			temp[l/2] = '\0';
			if(unit_distance(temp, ch + l/2))
				ans = true;
			else
			{
				f(i,l/2)
					temp[i] = ch[l-1-i];
				if(unit_distance(temp, ch))
					ans = true;
			}
		}
		else //l is even
		{
			char* temp = new char[l/2];
			f(i,l/2-1)
				temp[i] = ch[l/2-2-i];
			temp[l/2-1] = '\0';
			if(unit_distance(temp, ch + l/2))
				ans = true;
			else
			{
				f(i,l/2-1)
					temp[i] = ch[l-1-i];
				if(unit_distance(temp, ch))
					ans = true;
			}
		}

		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}