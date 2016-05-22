#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

multiset<int,greater<int> > m1;
multiset<int> m2;

void rebalance(){
	if(abs(m1.size() - m2.size()) <= 1)
		return;
	if(m1.size() > m2.size()){
		int x = *m1.begin(); m1.erase(m1.begin());
		m2.insert(x);
	}
	else{
		int x = *m2.begin(); m2.erase(m2.begin());
		m1.insert(x);
	}
}

// assumes that they are balanced
void printMedian(){
	ll ans = 0;
	if(m1.size() > m2.size())
		cout << *(m1.begin()) << endl;
	else if(m1.size() < m2.size())
		cout << *(m2.begin()) << endl;
	else{
		ans = (ll)(*m1.begin()) + (ll)(*m2.begin());
		if(ans == -1)
			cout << "-0.5" << endl;
		else if(ans%2 == 0)
			cout << ans/2 << endl;
		else
			cout << ans/2 << ".5" << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n,x; char ch; bool flag; 
	cin >> n;
	while(n--){
		cin >> ch >> x;
		flag = false;
		if(ch == 'a'){
			if(x <= *m1.begin())
				m1.insert(x);
			else
				m2.insert(x);
		}
		else{
			if(m1.count(x))
				m1.erase(m1.find(x));
			else if(m2.count(x))
				m2.erase(m2.find(x));
			else
				flag = true;
			if(m1.empty() && m2.empty())
				flag = true;
		}
		rebalance();
		if(flag)
			cout << "Wrong!" << endl;
		else
			printMedian();
	}
	return 0;
}