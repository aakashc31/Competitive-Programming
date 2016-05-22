#include <iostream>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

int main()
{
	int N;
	cin >> N;
	long long int s = 1;
	int* ar = new int[N];
	int* br = new int[N];
	f(i,N)
	{
		cin >> ar[i];
		br[i] = 0;
	}
	br[0] = 1;
	for(int i=1; i<N; i++)
	{
		if(ar[i] == ar[i-1])
		{
			s+=1;
			br[i] = 1;
		}
		else if(ar[i] > ar[i-1])
		{
			br[i] = br[i-1] + 1;
			s+=br[i];
		}
		else
		{
			if(br[i-1] != 1)
			{
				br[i] = 1;
				s+=1;
			}
			else
			{
				br[i] = 1;
				s+=1;
				int j = i-1;
				while(ar[j+1] < ar[j] && j>=0)
				{
					br[j] += 1;
					s+=1;
					if(j!=0 && br[j] < br[j-1] && ar[j-1] > ar[j])
					{
						break;
					}
					j--;
				}
			}
		}
	}
	cout << s << endl;
	return 0;
}