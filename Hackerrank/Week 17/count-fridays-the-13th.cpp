#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

typedef pair<int,int> pii;

#define elif else if

bool isLeap(int y){
	if(y%100 == 0)
		return (y%400)==0;
	return y%4;
}

int getDay(int d, int m, int y){
	int dval = d%7;
	int mval = 4; 
	if(m==1 || m==10)
		mval = 1;
	elif(m==4 || m == 7)
		mval = 0;
	elif(m==5)
		mval = 2;
	elif(m==6)
		mval = 5;
	elif(m==8)
		mval = 3;
	elif(m==12 || m==9)
		mval = 6;

	int yval1 = y/100;
	int yval = (5 - (yval1%7))%7;
	int rp = y%100;
	yval1 = (rp + rp/4)%7;
	yval += yval1;
	int toret =  (dval+mval+yval);
	if(isLeap(y) && m<=2)
		toret-=1;
	int centDiff = ((y - 2000)/100)%7;
	toret = (toret + 6*centDiff)%7;
	return toret;
}

int main(){
	int t, d1, m1, y1, d2, m2, y2;
	cin >> t;
	while(t--){
		cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
		if(d1 > 13) m1++;
		if(d2 < 13) m2--;
		int ans = 0;
		for(int y=y1; y<=y2; y++){
			int from = (y==y1) ? m1 : 1;
			int to = (y==y2) ? m2 : 12;
			for(int m=from; m<=to; m++){
				if(getDay(13,m,y) == 6)
					ans++;
			}
		}
		cout << ans << endl;
	}
	while(1){
		cin >> d1 >> m1 >> y1;
		cout << getDay(d1,m1,y1) << endl;
	}
	return 0;
}