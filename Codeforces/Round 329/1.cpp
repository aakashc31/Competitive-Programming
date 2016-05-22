#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

inline ll inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

int main(){
	ios::sync_with_stdio(false);
	vi ar[26][26];
	int n; cin >> n;
	vector<string> st; st.resize(n);
	f(i,n)
		cin >> st[i];
	f(i,n){
		vi cnt(26,0);
		f(j,st[i].size()){
			cnt[st[i][j]-'a']++;
		}
		ans = 0; fir = false, sec = false;
		f(j,26){
			if(cnt[j] != 0){
				if(!fir){
					fir = true;
					t1 = j;
				}
				else if(!sec){
					sec = true;
					t2 = j;
				}
				ans++;
			}
		}
		if(ans == 2){
			ar[t1][t2].pb(i);
		}
		else if(ans == 1){
			ar[t1][t1].pb(i);
		}
	}
	pii ans = mp(0,0);
	int maxVal = ar[0][0].size();
	f(i,26){
		f(j,26){
			if(i==j){
				if(ar[i][j].size() > maxVal){
					maxVal = ar[i][j].size();
					ans = mp(i,j);
				}
			}
			else{
				if(ar[i][j].size() + ar[i][i].size() + ar[j][j].size() > maxVal){
					maxVal = ar[i][j].size() + ar[i][i].size() + ar[j][j].size();
					ans = mp(i,j);
				}
			}
		}
	}
	if(ans.first == ans.second){
		f(i,ar[ans.first][ans.first].size()){
			cout << 
		}
	}
	return 0;
}