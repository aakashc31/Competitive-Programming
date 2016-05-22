#include <iostream>
#include <vector>
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
	int T;
	cin >> T;
	while(T-- > 0)
	{
		int N;
		cin >> N;
        int n = N;
		int* ar = new int[N];
		int* suffix = new int[N];
        f(i,N)
			cin >> ar[i];
         suffix[n-1] = n-1;
        for(int i=n-2; i>=0; i--)
            suffix[i] = (ar[i] > ar[suffix[i+1]]) ? i : suffix[i+1];
		int a = 0, b = N;
		long long int profit = 0;
		// invariant, maximum profit from each of the shares before index a has been computed.
		while(a<b)
		{
			//int max_index = max_element(ar+a, ar+b) - (ar+a);
			int max_index = suffix[a]-a;
            int max = *(ar+a+max_index);
			f(i,max_index)
			{
				profit += (max - *(ar+a+i));
			}
			a += max_index + 1;
		}
		cout << profit << endl;
	}

	return 0;
}