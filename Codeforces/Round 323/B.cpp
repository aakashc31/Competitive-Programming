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
typedef vector<vi>		vvi;
int ar[1000];

#define RIGHT true
#define LEFT false

bool isCollected[1000];

int main(){
	int n,a;
	cin >> n;
	f(i,n) {
		cin >> a;
		ar[i] = a;
	}
	int changes = 0;
	int collected = 0;
	bool flag = RIGHT;
	while(1){
		if(flag == RIGHT){
			for(int i=0; i<n; i++){
				if(ar[i] <= collected && (!isCollected[i])){
					collected++;
					isCollected[i] = true;
				}
			}
			if(collected == n){
				break;
			}
		}
		else if(flag == LEFT){
			for(int i=n-1; i>=0; i--){
				if(ar[i] <= collected && (!isCollected[i])){
					collected++;
					isCollected[i] = true;
				}
			}
			if(collected == n){
				break;
			}
		}
		if(flag == RIGHT){
			flag = LEFT;
			changes++;
		}
		else{
			flag = RIGHT;
			changes++;
		}
	}
	cout << changes << endl;
	return 0;
}