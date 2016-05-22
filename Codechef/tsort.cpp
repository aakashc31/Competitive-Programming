#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define f(i,n) for(int i=0;i<n;i++)

int main()
{
	int n;
	scanf("%d",&n);
	
	short int ar[1000001];
	f(i,1000001)
		ar[i] = 0;

	map<int,int> M;
	
	while(n-- > 0)
	{
		int t;
		scanf("%d",&t);
		if(ar[t]==-1)
		{
			M[t] = M.find(t)->second + 1;
		}
		else if(ar[t]==1)
		{
			M[t] = 2;
			ar[t] = -1;
		}
		else
			ar[t]++;
	}

	f(i,1000001)
	{
		int numPrint = 0;
		if(ar[i]==-1)
			numPrint = M.find(i)->second;
		else
			numPrint = ar[i];
		f(j,numPrint)
			printf("%d\n", i);
	}
	return 0;
}