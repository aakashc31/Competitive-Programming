#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	int ar[] = {1,2,3,4,5,6};
	while(1){
		int x;
		cin >> x;
		cout << binary_search(ar, ar+6, x) << endl;
		if(!binary_search(ar, ar+6, x))
			cout << "not" << endl;
		else
			cout << "yes" << endl;
	}
}