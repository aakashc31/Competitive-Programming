#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

ll ar[300000];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	int i = 0, j = 0;
	ll maxTillNow = 0, maxEndingHere = 0;
	while(i<n && j<n && i<=j){
		maxEndingHere += ar[j];
		if(i == j){
			if(maxEndingHere <= m){
				maxTillNow = max(maxTillNow, maxEndingHere);
				j++;
			}
			else
				i++, j++;
		}
		else{
			if(maxEndingHere <= m){
				maxTillNow = max(maxTillNow, maxEndingHere);
				j++;
			}
			else{
				while(maxEndingHere > m && i < j){
					maxEndingHere -= ar[i];
					i++;
				}
				if(ar[j] > m){
					j++;
					i = j;
				}
				else{
					maxTillNow = max(maxTillNow, maxEndingHere);
					j++;
				}
			}
		}
	}
	cout << maxTillNow << endl;
	return 0;
}