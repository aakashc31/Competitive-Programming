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
	int t;
	cin >> t;
	while(t-- > 0)
	{
		int n;
		cin >> n;
		int ar[100][100];
		int k = (n>100)?100:n;
		f(i,k)
		{
			f(j,i+1)
			{
				scanf("%d",&ar[i][j]);
			}
		}
		if(n>100)
		{
			for(int i = 100; i<n; i++)
			{
				f(j,i+1)
				{
					int l;
					scanf("%d",&l);
				}
			}
		}

		//printing the inputed array
		// f(i,k)
		// {
		// 	f(j,i+1)
		// 	{
		// 		printf("%d ",ar[i][j]);
		// 	}
		// 	printf("\n");
		// }

		int maxVal[k][k];
		int max1 = ar[0][0];
		maxVal[0][0] = max1;
		for(int i=1; i<k;i++)
		{
			f(j,i+1)
			{
				if(i==j)
				{
					if(maxVal[i-1][j-1]<0)
						maxVal[i][j] = -1;
					else
					{
						maxVal[i][j] = maxVal[i-1][j-1] + ar[i][j];
						// printf("%d,%d-%d\n",i,j,maxVal[i][j]);
					}
				}

				else if(j==0)
				{
					if(maxVal[i-1][0] < 0)
						maxVal[i][0] = -1;
					else
					{
						maxVal[i][0] = maxVal[i-1][0] + ar[i][0];
						// printf("%d,%d-%d\n",i,j,maxVal[i][j]);
					}
				}
				else
				{
					if(maxVal[i-1][j-1] < 0 && maxVal[i-1][j] < 0)
						maxVal[i][j] = -1;
					else
					{
						maxVal[i][j] = max(maxVal[i-1][j], maxVal[i-1][j-1]) + ar[i][j];
						// printf("%d,%d-%d\n",i,j,maxVal[i][j]);
					}
				}
			}
		}
		max1 = -1;
		f(i,k)
		{
			if(maxVal[k-1][i] > max1)
				max1 = maxVal[k-1][i];
		}
		printf("%d\n", max1);
	}

	return 0;
}