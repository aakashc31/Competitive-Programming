#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;


pii compute(string s1, string s2){
	int ans = 0;
	for(int i=0; i<s1.length();i++){
		if(s1[i]==s2[i])
			ans++;
	}
	pii ret = mp(ans, 0);
	for(int i=0; i<s1.length(); i++){
		for(int j=0; j<s1.length(); j++){
			if(s1[i] == s2[j] && (i!=j))
				ret.second++;
		}
	}
	return ret;
}

int main(){
	char ar[] = {'0','2','3','6','8','8'};
	// string all[] = {"111111", "333333", "444444", "555555", "666666", "999999"};
	do{
		string s = "";
		for(int i=0; i<6; i++)
			s+=ar[i];
		cout << s << endl;
		// bool ans = true;
		// for(int i=0; i<6; i++){
		// 	pii ret = compute(s, all[i]);
		// 	cout << ret.first << " " << ret.second << endl;
		// 	if(ret.first == 1 && ret.second == 5){
				
		// 	}
		// 	else{
		// 		ans = false;
		// 	}
		// }
		// if(ans) {
		// 	cout << s << endl;
		// 	break;
		// }

	}while(next_permutation(ar, ar+6));
	return 0;
}
