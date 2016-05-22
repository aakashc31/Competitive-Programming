#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define mp make_pair
#define pb push_back

#define getcx getchar//_unlocked
typedef long long int lli;

inline int inp()//fast input function
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
	int t,n,m,a;
	t = inp();
	while(t--){
		n = inp();
		m = inp();
		int numOnes = 0;
		vi ar(0);
		for(int i=0; i<m; i++){
			a = inp();
			ar.pb(a);
			if(a==1) numOnes++;
		}
		if(numOnes == m){
			cout << m/2 << endl;
			continue;
		}
		if(m<=100){
			sort(ar.begin(), ar.end());
			int ans = 0;
			while(ar.size() > 1){
				vi temp(0);
				int i = ar.size()-1;
				if(ar[0] > i/2){
					temp.pb(ar[0]);
					while(i>0){
						if(i!=1){
							temp[0]--;
							ans++;
							temp.pb(ar[i] + ar[i-1]+1);
							i-=2;
						}
						else{
							temp.pb(ar[i]);
							i--;
						}
					}
				}
				else{
					for(int j = 0; j < ar[0]; j++){
						temp.pb(ar[i] + ar[i-1]+1);
						ans++;
						i-=2;
					}
					while(i>0){
						temp.pb(ar[i]);
						i--;
					}
				}
				sort(temp.begin(), temp.end());
				ar = temp;
				if(ar.size() == 2){
					ans++;
					break;
				}
			}
			cout << ans << endl;
		}
		else{
			sort(ar.begin(), ar.end());
			int ans = 0;
			int low = 0, high = ar.size()-1;
			while(low < high){
				// cout << "low = " << low << ", high = " << high << endl;
				if(high - low == 1){
					ans++;
					break;
				}
				int k = min(ar[low], (high - low)/2);
				for(int i=0; i<k; i++){
					ar[high-2*k + i + 1] = ar[high - 2*k + 2*i + 1] + ar[high - 2*k + 2*i + 2] + 1;
				}
				if(k==ar[low])
					low++;
				else
					ar[low] -= k;
				high -= k;
				ans += k;
			}
			cout << ans << endl;
		}
	}
	return 0;
}