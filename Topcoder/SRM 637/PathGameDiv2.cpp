#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define f(i,n) for(int i=0 ;i<n; i++)


class PathGameDiv2 {
public:
	int calc(vector <string> board) 
	{
		int l = board[0].size();
		int ar[2][l];
		// base case
		ar[0][0] = board[0][0]=='.'?1:-1;
		ar[1][0] = board[1][0]=='.'?1:-1;
		int cnt = 0;
		if(board[0][0]=='.') cnt++;
		if(board[1][0]=='.') cnt++;
		for(int j=1; j<l; j++)
		{
			if(board[0][j]=='.')cnt++;
			if(board[1][j]=='.')cnt++;
			bool is0set = false, is1set = false;
			if(board[0][j]=='.')
			{
				if(board[0][j-1]=='.')
				{
					ar[0][j] = 1+ar[0][j-1];
					is0set = true;
				}
			}
			else
			{
				ar[0][j]=-1;
				is0set = true;
			}

			if(board[1][j]=='.')
			{
				if(board[1][j-1]=='.')
				{
					ar[1][j] = 1+ar[1][j-1];
					is1set = true;
				}
			}
			else
			{
				ar[1][j]=-1;
				is1set = true;
			}

			if(!is0set)
			{
				is0set = true;
				ar[0][j] = ar[1][j]+1;
			}
			if(!is1set)
			{
				is1set = true;
				ar[1][j] = ar[0][j] +1;
			}
		}
		int ans;
		if(ar[0][l-1]>0 && ar[1][l-1]>0)
			ans = min(ar[0][l-1], ar[1][l-1]);
		else if(ar[0][l-1]>0)
			ans = ar[0][l-1];
		else
			ans = ar[1][l-1];
		return (cnt-ans);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	PathGameDiv2 *obj;
	int answer;
	obj = new PathGameDiv2();
	clock_t startTime = clock();
	answer = obj->calc(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"#....","...#."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"#","."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {".","."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"....#.##.....#...........","..#......#.......#..#...."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 13;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
