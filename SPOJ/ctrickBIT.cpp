#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define LSOne(n) (n & (-n))

class BIT{
private:
	vector<int> ft;
public:
	BIT(int n){
		ft.resize(n+1, 0);
	}
	inline int query(int a){
		int sum = 0;
		for(; a > 0; a -= LSOne(a))
			sum += ft[a];
		return sum;
	}
	inline int query(int a, int b){
		if(a>b) return 0;
		return query(b) - ((a==1) ? 0 : query(a-1));
	}
	inline void update(int k, int x){
		for(; k < ft.size(); k += LSOne(k))
			ft[k] += x;
	}
	inline int ithZero(int k){
		int low = 1, high = ft.size(), mid;
		while(low < high){
			mid = (low + high)/2;
			if(query(mid) >= k)
				high = mid;
			else
				low = mid+1;
		}
		return low;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(n==1){
			cout << 1 << endl; continue;
		}
		BIT* b = new BIT(n);
		vi ans(n+1,0);
		for(int i=0; i<n; i++)
			b->update(i+1, 1);
		b->update(2,-1);
		ans[2]=1; int curr = 2;
		int lz,rz,z;
		for(int i=2; i<=n; i++){
			lz = b->query(1,curr), rz = b->query(curr,n);
			z = (i % (lz+rz)) + 1;
			if(z <= rz)
				curr = b->ithZero(z+lz);
			else
				curr = b->ithZero(z-rz);
			ans[curr] = i;
			b->update(curr, -1);
		}
		for(int i=0; i<n; i++)
			cout << ans[i+1] << " ";
		cout << endl;
	}
	return 0;
}