#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> S;
	for(int i=1; i<10; i++)
		S.insert(i*10);
	set<int>::iterator it = S.lower_bound(145); it--;
	cout << *it << " " << *S.upper_bound(45) << endl;
	return 0;
}