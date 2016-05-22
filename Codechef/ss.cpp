#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define f(i,n) for(int i=0;i<n;i++)
 
 
 
 
int main()
{
	int T;
	cin >> T;
	while(T-- > 0)
	{
		int n; // #men =  #women
		cin >> n;
		//take input and store after subtracting one from them
		//while outputting add one and print
		int wp[n][n];//women's pref
		int mp[n][n];//men's pref
 
		// input women's prefs
		f(i,n)
		{
			int w;
			cin >> w;
			w--;
			//wth women
			//now input her prefs
			f(j,n)
			{
				int k;
				cin >> k;
				k--;
				wp[w][j] = k;
			}
		}
 
		// input men's prefs
		f(i,n)
		{
			int w;
			cin >> w;
			w--;
			//wth man
			//now input his prefs
			f(j,n)
			{
				int k;
				cin >> k;
				k--;
				mp[w][j] = k;
			}
		}
 
		int marriage[n]; //index of the man to whom the ith woman is married, if woman is unmarried then -1
		int rev_marriage[n]; //index of the woman to whom the ith man is married, if man is unmarried then -1
		int pointer[n]; //this will contain the position which ith woman must propose next
		stack<int> wtomarry; //this contains the indices of those women who are yet unmarried
		f(i,n)
		{
			pointer[i] = 0;
			marriage[i] = rev_marriage[i] = -1;
			wtomarry.push(n-1-i);
		}
		
		while(!wtomarry.empty())
		{
			int present_woman = wtomarry.top();
			wtomarry.pop();
			int i;
			for(i = pointer[present_woman]; i<n; i++)
			{
				int next_proposed = wp[present_woman][i]; //this is the man present_woman is proposing
				if(rev_marriage[next_proposed] == -1)
				{
					marriage[present_woman] = next_proposed;
					rev_marriage[next_proposed] = present_woman;
					// cout << present_woman+1 <<" marries "<<next_proposed+1<<endl;
					i++;
					break;
				}
				else
				{
					int currently_married = rev_marriage[next_proposed];
					int flag = 0;
					f(j,n)
					{
						if(mp[next_proposed][j]==currently_married)
						{
							flag = 1;
							break;
						}
						else if(mp[next_proposed][j] == present_woman)
						{
							break;
						}
					}
					//flag 0 means that present woman has greater preference than currently married woman
 
					if(flag == 1)
					{
						//do nothing
					}
					else
					{
						//puraani shaadi todni paregi
						marriage[present_woman] = next_proposed;
						rev_marriage[next_proposed] = present_woman;
						marriage[currently_married] = -1;
						wtomarry.push(currently_married);
						// cout << currently_married+1 << " broken with "<<next_proposed+1<<endl;
						// cout << present_woman+1 << " married "<<next_proposed+1<<endl;
						i++;
						break;
					}
				}
			}
			pointer[present_woman] = i;
		}
 
		f(i,n)
		{
			cout << i+1<< " "<< rev_marriage[i]+1<<endl;
		}
 
		// test code
		
	}
 
	return 0;
 
} 