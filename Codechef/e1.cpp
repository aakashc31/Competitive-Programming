// white knight
// huh!
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)

int numrow;
int numcol;

short int get(short int ar[][1000],int i, int j) //fine
{
	if(i>=0 && i<numrow && j>=0 && j<numcol)
		return ar[i][j];
	else
		return -1;
}

short int maximum(short int a, short int b, short int c, short int d) //fine
{
	short int ar[4];
	short int max = a;
	ar[0] = a, ar[1] = b, ar[2] = c, ar[3] = d;
	f(i,4)
	{
		if(ar[i]>max)
			max = ar[i];
	}
	return max;
}

int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int n;
		getNum(n);
		char ch[n][n+1];
		int I,J;
		bool flag = true; //false if K has been found
		f(i,n)
		{
			scanf("%s",&ch[i]);
			if(flag)
			{
				f(j,n)
				{
					if(ch[i][j]=='K')
					{
						I=i;J=j;
						flag = false;
					}
				}
			}
		}
		//input and position of knight located
		numcol = numrow = n;
		//base case
		short int ar[n][1000];
		if(J==n-1)
		{
			printf("0\n");
			continue;
		}
		f(i,n)
		{
			ar[i][J] = -1;
			ar[i][J+1] = -1;
		}
		ar[I][J] = 0;
		if(I+2<n && ch[I+2][J+1]=='P')
			ar[I+2][J+1] = 1;
		else
			ar[I+2][J+1] = 0;
		if(I-2>=0 && ch[I-2][J+1]=='P')
			ar[I-2][J+1] = 1;
		else
			ar[I-2][J+1] = 0;
		//base over

		for(int j=J+2; j<n; j++)
		{
			f(i,n)
			{
				int set = -1;
				// cout << get(ar,i-2,j-1) << ", " << get(ar,i+2,j-1) << ", " << get(ar,i-1,j-2) << ", " << get(ar,i+1,j-2) <<endl;
				int max = maximum(get(ar,i-2,j-1),get(ar,i+2,j-1),get(ar,i-1,j-2),get(ar,i+1,j-2));
				// cout << i << "," <<j <<" : "<<max <<endl;
				if(max!=-1)
				{
					set = max;
					if(ch[i][j]=='P')
						set++;
				}
				ar[i][j] = set;
			}
		}

		int max = 0;
		f(i,n)
		{
			if(ar[i][n-1] > max)
				max = ar[i][n-1];
			// cout << i <<","<<n-1<<" = "<<ar[i][n-1] <<endl;
		}
		printf("%d\n", max);
		// printing the final ar[][]
		// f(i,n)
		// {
		// 	f(j,n)
		// 		cout << ar[i][j] << " ";
		// 	cout << endl;
		// }

	}
	return 0;
}