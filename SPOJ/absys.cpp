#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;

int stringToInt(string s){
	int ret = 0;
	for(int i=0; i<s.length(); i++)
		ret = ret * 10 + (s[i] - '0');
	return ret;
}

int main(){
	int t;
	string s1, s2, s3;
	cin >> t;
	while(t--){
		cin >> s1;
		cin >> s2;
		cin >> s2;
		cin >> s3;
		cin >> s3;
		// cout << s1 << " " << s2 << " " << s3 << endl;
		size_t found = s1.find("machula");
		if(found != string::npos){
			int num = stringToInt(s3) - stringToInt(s2);
			cout << num << " + " << s2 << " = " << s3 << endl;
		}
		else{
			found = s2.find("machula");
			if(found != string::npos){
				int num = stringToInt(s3) - stringToInt(s1);
				cout << s1 << " + " << num << " = " << s3 << endl;
			}
			else{
				int num = stringToInt(s1) + stringToInt(s2);
				cout << s1 << " + " << s2 << " = " << num << endl;
			}
		}
	}
	return 0;
}