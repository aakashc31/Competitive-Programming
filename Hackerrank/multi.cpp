#include <bits/stdc++.h>
using namespace std;


int kthLargest(multiset<int> m, int k, int low, int high){

}

int main(){
	multiset<int> m;
	for(int i=0; i<10; i++)
		m.insert(10-i);
	for(multiset<int>::iterator it = m.begin(); it!=m.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	multiset<int>::iterator it = m.lower_bound(5);
	// it = (m.begin() + m.end())/2;
	cout << distance(m.begin(),it) << endl;
	return 0; 
}