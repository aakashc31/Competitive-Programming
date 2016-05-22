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
	string st;
	cin >> st;
	int count[26];
	f(i,26)
	{
		count[i]=0;
	}
	int len = st.length();
	f(i,len)
	{

		int asc = (int)(st[i]) - 97;
		cout << st[i] << " "<<asc<<endl;
		count[asc]++;
	}
	int numodd = 0;
	f(i,26)
	{
		if(count[i]%2!=0)
			numodd++;
	}
	if(numodd>1)
		cout << "NO";
	else
		cout <<"YES";
}