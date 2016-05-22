#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		unsigned int a,b;
		cin >> a >> b;
		int l1 = __builtin_clz(a);
		int l2 = __builtin_clz(b);
		if(l1 != l2)
			cout << 0 << endl;
		else{
			unsigned int ans = 0;
			int msb = (32-l1-1);
			ans |= (1<<msb);
			for(int i=0; i<msb; i++){
				if(a&(1<<i)){
					// cout << i << " bit is on" << endl;
					unsigned int suffix = a & (((1<<(i+1))-1)); //1X
					// cout << "suffix = " << suffix << endl;
					if(b-a < (1<<(i+1)) - suffix){
						// cout << "Taking this bit\n";
						ans |= (1<<i);
					}
					// else
						// cout << "Ignoring this bit\n";
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}