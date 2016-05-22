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

int ar[20]; //satisfaction

int rules[20][20];
bool flag[20];
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	int x,y,c;
	for(int i=0; i<k; i++){
		cin >> x >> y >> c;
		x--; y--;
		rules[x][y] = c;
	}

	int mask = 0, ans = 0;
	for(int i=0; i<(1<<n); i++){
		if(__builtin_popcount(i) != m)
			continue;
		vi select(0);
		for(int j=0; j<n; j++){
			if(i & (1<<j))
				select.push_back(j);
		}
		//now compute max satisfaction for this selection
		memset(flag, 1, m);
		vi ordering(m);
		for(int l = 0; l < m-1; l++){
			vi best(m,0);
			for(int j=0; j<select.size(); j++){
				for(int p=0; p<select.size();p++){
					if(flag[j] && flag[p])
						best[j] = max(best[j], rules[select[j]][select[p]]);
				}
			}
			int minBest = (1<<30);
			int index = -1;
			for(int j=0; j<select.size(); j++){
				if(flag[j]){
					if(best[j] < minBest){
						index = j;
						minBest = best[j];
					}
				}
			}
			flag[index] = false;
			ordering[m-1-l] = select[index];
			cout << "select[index] = " << select[index]+1 << ", best = " << minBest << endl;

		}
		for(int l = 0; l < m; l++){
			if(flag[l]){
				ordering[0] = select[l];
				break;
			}
		}
		cout << "ordering: ";
		for(int l =0; l<ordering.size(); l++)
			cout << ordering[l]+1 << " " ;
		cout << endl;
		int sat = 0;
		for(int l=0; l<m-1; l++){
			sat += rules[ordering[l]][ordering[l+1]];
			sat += ar[ordering[l]];
		}
		sat += ar[ordering[m-1]];
		ans = max(sat, ans);
	}
	cout << ans << endl;
	return 0;
}