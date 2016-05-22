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


map<pair<int,int>,int> M;
int mod = 1000000007;
int compute(int a, int b)
{
	if(a<=b)
		swap(a,b);
	//a contains maximum element now.
	if(a<25)
		{
			pair<int,int> p(a,b);
			if(M.find(p)==M.end())
			{
				long long int sum  = a + b;
				long long int ans = 1;
				long long int todiv = 1;
				f(i,b)
				{
					ans *= (sum-i);
					todiv*=(i+1);
					if(ans%todiv==0)
					{
						ans = ans/todiv;
						todiv = 1;
					}
				}
				// cout << ans << endl;
				M[p] = ans%mod;
				// cout << M[p] <<endl;
				return ans%mod;
			}
			else
			{
				return M.find(p)->second;
			}
		}
	else if(a==25 && b<=23)
		return 0;
	else if((a-b)>=2)
		return 0;
	else
		{
			pair<int,int>p(a,b);
			if(M.find(p)==M.end())
			{
				int a1 = compute(a,b-1);
				int a2 = compute(a-1,b);
				long long int s = a1+a2;
				long long int ans = s%mod;
				M[p] = ans;
				return ans;
			}
			else
			{
				return M.find(p)->second;
			}
		}
	return 0;
}

int main()
{
	int a,b;
	cin >> a>>b;
	if(a<=b)
		swap(a,b);
	//a contains maximum element now.
	if((a<25) || a==b)
		cout << "0";
	else if(a==25 && b<24)
		{

			int sum = 24 + b;
			long long int ans = 1;
			long long int todiv = 1;
			f(i,b)
			{

				ans *= (25+i);
				todiv*=(i+1);
				if(ans%todiv==0)
					{ans/=todiv; todiv =1;
					}

			}
			cout << ans%mod << endl;
		}
	else if((a-b)!=2)
		cout << "0";
	else
		{
			cout << compute(a-1,b)<<endl;
		}
	return 0;
}

//it took me a long time code this..
// Reason being I didn't estimate the size of the combinations beforehand. This led to too many errors.
// What I learnt is dynamic prog solving power. And, size k loche. And how to solve it. 