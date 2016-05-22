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
	cin>>T;
	while(T-- > 0)
	{
		int M,N;
		cin >> M >> N;
		int* ar = new int[N];
		vector<int> v(0,0);
		f(i,N)
		{
			cin>>ar[i];
			v.push_back(ar[i]);
		}
		sort(all(v));
		f(i,N)
		{
			int ith = v[i];
			if(binary_search(v.begin()+i+1,v.end(),M-ith))
			{
				int p=0,q=0,flag=0;
				f(j,N)
				{
					if(ar[j]==ith && flag==0)
						{p=j;flag=1;}
					if(ar[j]==(M-ith))
						q=j;
				}
				int max = p>q?p:q;
				int min = p>q?q:p;
				cout<<min+1<<" "<<max+1<<endl;

			}
		}

	}
}