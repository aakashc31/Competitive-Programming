#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

inline ll inp()//fast input function
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	double x1, y1, x2, y2, vmax, t, vx, vy, wx, wy, x, y;
	cin >> x1 >> y1 >> x2 >> y2 >> vmax >> t >> vx >> vy >> wx >> wy;
	double l = 0.0, r = 1e9, m;
	f(i,400){
		m = (l+r)/2;
		x = x1 + min(m,t) * vx + max(0.0,m-t) * wx;
		y = y1 + min(m,t) * vy + max(0.0, m-t) * wy;
		((hypot(x-x2, y-y2) < m*vmax) ? r : l) = m;
	}
	cout << r << endl;
	return 0;
}