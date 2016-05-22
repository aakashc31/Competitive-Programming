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
		if(m<=100 && false){
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
		// else{
		// 	sort(ar.begin(), ar.end());
		// 	int smallest = ar[0];
		// 	int numElements = m;
		// 	int curr = 0;
		// 	int ans = 0;
		// 	while(1){
		// 		if(numElements == 1)
		// 			break;
		// 		if(numElements == 2){
		// 			ans++;
		// 			break;
		// 		}
		// 		if(smallest > (numElements-1)/2){
		// 			ans += (numElements-1);
		// 			break;
		// 		}
		// 		else if(smallest < (numElements-1)/2){
		// 			numElements = numElements - 1 - smallest;
		// 			ans += smallest;
		// 			smallest = ar[curr+1];
		// 			curr++;
		// 		}
		// 		else{
		// 			numElements = numElements - 1 - smallest;
		// 			ans += smallest;
		// 			smallest = ar[curr+1] + ar[curr+2];
		// 			curr+=2;
		// 		}
		// 	}
		// 	cout << ans << endl;
		// }
		else{
			sort(ar.begin(), ar.end());
			vector<int> temp;
			int ans = 0;
			while(1){
				// cout << "ar.size() = " << ar.size() << ", ans = " << ans << endl;
				// for(int i=0; i<ar.size(); i++)
				// 	cout << ar[i] << " ";
				// cout << endl;
				if(ar.size() == 1)
					break;
				if(ar.size() == 2){
					ans++;
					break;
				}
				int i=0;
				int s = ar[0];
				if(s - 1 > (ar.size()-1)/2){
					ans += (ar.size()-1);
					break;
				}
				while(i < ar.size()-1 && s < (ar.size()-1-i)/2){
					i++;
					s += ar[i];
				}
				// cout << "i = " << i << endl;
				if(s == (ar.size()-1-i)/2){
					temp.clear();
					ans += s;
					if((ar.size()-1-i)&1){
						temp.pb(ar[i+1]);
						i++;
					}
					i++;
					while(i<ar.size()){
						temp.pb(ar[i] + ar[i+1] + 1);
						i+=2;
					}
					ar = temp;
				}
				else if(s>(ar.size()-1-i)/2){
					temp.clear();
					ans += (ar.size()-1-i)/2;
					temp.pb(s - (ar.size()-1-i)/2);
					if((ar.size()-1-i)&1){
						temp.pb(ar[i+1]);
						// temp[0] += ar[i+1];
						// ans++;
						i++;
					}
					i++;
					while(i<ar.size()){
						temp.pb(ar[i] + ar[i+1] + 1);
						i+=2;
					}
					ar = temp;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}