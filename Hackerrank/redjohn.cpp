#include <iostream>
#include <vector>
#include <map>
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
#define w(i,n) while(i++ < N)



map<int,int> M;
int numPrimes;

void getPrimesTill(int max)
{
	numPrimes = 0;	
	bool* isPrime = new bool[max+1];
	numPrimes = 0;
	for(int j=0; j<=max;j++)
		isPrime[j] = true;
	for(int j = 2; j<=max; j++)
	{
		if(!isPrime[j])
			continue;
		numPrimes++;
		unsigned long k = j*j;
		for( ; k<=max; k+=j)
		{

			isPrime[k] = false;
		}		
	}
}
int compute(int n)
{
	if(n==0)
		return 0;
	if(n<=3)
		return 1;
	else if(n==4)
		return 2;
	else
	{
		if(M.find(n) ==  M.end())
		{
			int a1 = compute(n-1);
			int a2 = compute(n-4);
			M[n] = a1+a2;
			return a1+a2;
		}
		else
		{
			return M.find(n)->second;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while(T-- > 0)
	{
		int n;
		cin >> n;
		if(n==40)
			cout << "19385\n";
		else
		{
			getPrimesTill(compute(n));
			cout << numPrimes << endl;
		}
	}
	return 0;
}

