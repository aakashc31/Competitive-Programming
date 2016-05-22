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

double power_rep(double p, int power){
	if(power == 0)
		return 1.0;
	if(power & 1){
		double halfPower = power_rep(p, (power>>1));
		return halfPower*halfPower*p;
	}
	else{
		double halfPower = power_rep(p, (power>>1));
		return halfPower*halfPower;
	}
}

double compute(double p, int m){
	double curr = p * 1000000000.0;
	double ans = curr;

	for(int i=2; i<m; i++){
		curr *= p;
		if(i&1)
			ans += curr;
		else
			ans -= curr;
	}
	return ans;
}

int main(){
	int t,m;
	double p;
	cin >> t;
	while(t--){
		cin >> m;
		cin >> p;
		double total = 1000000000.0;
		if(m == 1)
			cout << fixed << total << " " << 0.0 << endl; 
		else if(p == 1){
			if(m&1)
				cout << fixed << total << " " << 0.0 << endl; 
			else
				cout << fixed << 0.0 << " " << total << endl;
		}
		else if(m == 2){
				cout << fixed << (1-p)*total << " " << p*total << endl;
		}
		else if(m == 3){
				cout << fixed << (1-p + p*p)*total << " " << (p - p*p)*total << endl;
		}
		else if(m <= 1000){
			double second = compute(p, m);
			cout << fixed << total - second << " " << second << endl;
		}
		else{
			double s1=0,s2=0;
			if(m&1){
				int k = (m-1)/2;
				s1 = (total*p*(1-power_rep(p, 2*k)))/(1-p*p);
				s2 = (total*p*p*(1-power_rep(p, 2*k)))/(1-p*p);
			}
			else{
				int k = (m-2)/2;
				s1 = (total*p*(1-power_rep(p, 2*k+2)))/(1-p*p);
				s2 = (total*p*p*(1-power_rep(p, 2*k)))/(1-p*p);
			}
			double second = s1 - s2;
			cout << fixed << total-second << " " << second << endl;
		}
	}
	return 0;
}