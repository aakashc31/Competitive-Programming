#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) init((a).size()) 
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
	int mod = 100000007;
	while(T-- > 0)
	{
		int init,slot1,slot2,K,N;
		cin >> init >> slot1 >> slot2 >> K >> N;
		if(N==1)
			cout << init%mod << endl;
		else if(N>1 && N<=1+slot1)
		{
			int i = 2;
			long long int s = init+1;
			while(i++<N)
				s+=1;
			cout << s%mod << endl;
		}

		else if(N<=1+slot2+slot1)
		{
			int i = 2;
			long long int s = init+1;
			while(i++<1+slot1)
				s+=1; 
			while(i++<N)
				s*=2;
		}

		else
		{
			int i = 2;
			long long int s = init+1;
			while(i++<1+slot1)
				s+=1;
			//after this you'll have to maintain a sliding window of first element and sum. As window moves ahead, 
			while(i++<1+slot2+slot1)
				s*=2;
		}
	}
	return 0;
}
