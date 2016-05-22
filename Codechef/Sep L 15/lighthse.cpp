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
	int t,n,x,y;
	t = inp();
	while(t--){
		vector<pii> vx;
		vector<pii> vy;
		vector<pii> v;
		n = inp();
		for(int i=0; i<n; i++){
			x = inp();
			y = inp();
			vx.pb(mp(x,i));
			vy.pb(mp(y,i));
			v.pb(mp(x,y));
		}
		sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());

		set<int> minX;
		minX.insert(vx[0].second);
		int i=1;
		while(i<n && vx[i-1].first == vx[i].first){
			minX.insert(vx[i].second);
			i++;
		}

		set<int> maxX;
		maxX.insert(vx[n-1].second);
		i = n-2;
		while(i>=0 && vx[i+1].first == vx[i].first){
			maxX.insert(vx[i].second);
			i--;
		}

		int config = -1;
		int answer = -1;
		int val = vy[0].first;
		i = 0;
		while(i<n){
			if(vy[i].first != val)
				break;
			if(minX.count(vy[i].second)){
				config = 0;
				answer = vy[i].second;
				break;
			}
			if(maxX.count(vy[i].second)){
				config = 1;
				answer = vy[i].second;
				break;
			}
			i++;
		}
		if(config != -1){//answer mil gaya hai
			cout <<  "1" << endl;
			cout << answer+1 << " ";
			if(config == 0) cout << "NE" << endl;
			else cout << "NW" << endl;
			continue;
		}

		i=n-1;
		val = vy[n-1].first;
		while(i>=0){
			if(vy[i].first != val)
				break;
			if(minX.count(vy[i].second)){
				config = 2;
				answer = vy[i].second;
				break;
			}
			if(maxX.count(vy[i].second)){
				config = 3;
				answer = vy[i].second;
				break;
			}
			i--;
		}
		if(config != -1){
			cout << 1 << endl;
			cout << answer+1 << " ";
			if(config == 2) cout << "SE" << endl;
			else cout << "SW" << endl;
			continue;
		}

		// if here, can't be done using one light
		i=1;
		while(i<n && vx[i-1].first == vx[i].first){
			i++;
		}
		cout << 2 << endl;
		int p1 = vx[0].second;
		int currY = v[p1].second;
		int p2 = vx[i].second;

		if(v[p1].second  > v[p2].second){
			//find the point with max y
			for(int j=1; j<i; j++){
				if(v[vx[j].second].second > currY){
					p1 = vx[j].second;
					currY = v[p1].second;
				}
			}
			cout << p1+1 << " SE" << endl;
			cout << p2+1 << " NE" << endl;
		}
		else{
			//find the point with min y
			for(int j=1; j<i; j++){
				if(v[vx[j].second].second < currY){
					p1 = vx[j].second;
					currY = v[p1].second;
				}
			}
			cout << p1+1 << " NE" << endl;
			cout << p2+1 << " SE" << endl;
		}

	}
	return 0;

}