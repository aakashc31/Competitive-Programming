#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

#define getcx 			getchar//_unlocked
inline ll inp(){
	ll n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

int main(){
	int t = inp(),n,x,y;
	while(t--){
		n = inp();
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		for(int i=0; i<n; i++){
			x = inp(); y = inp(); pq.push(mp(y,x));
		}
		int ans = 0;
		while(!pq.empty()){
			pii curr = pq.top(); pq.pop();
			while(!pq.empty() && pq.top().second < curr.first)
				pq.pop();
			ans++;
		}
		printf("%d\n", ans);
	} 
	return 0;
}