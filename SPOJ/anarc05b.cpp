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
int A[10000], B[10000];
ll sa[10000][2], sb[10000][2];
int n,m;
int inf = 1000000000;

int compute(int index, int isSwitch, int isA){
	if(isA == 1){
		if(index >= n)
			return 0;
		if(sa[index][isSwitch] != (-inf))
			return sa[index][isSwitch];
		if(isSwitch == 0){
			//no switching here
			ll ans = A[index];
			ans += max(compute(index+1, 0, 1), compute(index+1, 1, 1));
			sa[index][isSwitch] = ans;
			return ans;
		}
		else{
			//switch here
			if(binary_search(B, B+m, A[index])){
				int otherIndex = lower_bound(B, B+m, A[index]) - B;
				sa[index][isSwitch] = compute(otherIndex, 0, 0);

				return sa[index][isSwitch];
			}
			else{
				return sa[index][isSwitch];
			}
		}
	}

	if(index >= m)
		return 0;
	if(sb[index][isSwitch] != (-inf))
		return sb[index][isSwitch];
	if(isSwitch == 0){
		ll ans = B[index];
		ans += max(compute(index+1, 0, 0), compute(index+1, 1, 0));
		sb[index][isSwitch] = ans;
		return ans;
	}
	else{
		if(binary_search(A, A+n, B[index])){
			int otherIndex = lower_bound(A, A+n, B[index]) - A;
			sb[index][isSwitch] = compute(otherIndex, 0, 1);
			return sb[index][isSwitch];
		}
		else{
			return sb[index][isSwitch];
		}
	}
}

int main()
{
	cin >> n;
	// printf("Yo%d\n",n);
	while(n!=0)
	{
		for(int i=0; i<n; i++){
			cin >> A[i];
			sa[i][0] = sa[i][1] = -inf;
		}
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> B[i];
			sb[i][0] = sb[i][1] = -inf;
		}
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				compute(0,i,j);
			}
		}
		cout << max(max(sa[0][0], sa[0][1]), max(sb[0][0], sb[0][1])) << endl;
		cin >> n;
	}
	return 0;
}