// palin_u is faster and correct.
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

// returns the integer at the ith location in the string st
int getIntAt(string st, int i)
{
	char ch = st[i];
	int asc = (int)ch;
	asc-=48;
	return asc;
}

// adds one to the number a and returns the new string
string successor(string a) 
{
	
	string sum = "";
	int carry = 1;
	int lmax = a.length();
	int i = 0;
	for(i=0;i<lmax;i++)
	{
		int l1 = getIntAt(a,lmax-1-i);
		
		int s = l1+carry;
		carry = s/10; 
		s = s%10;
		//cout<<"carry = "<<carry<<" sum = "<<s<<endl;
		char last = (char)(s+48);
		sum = last + sum;
		if(carry==0)
		{
			break;
		}
	}
	if(carry==1)
		sum = "1"+sum;
	if(i<lmax)
	{
		sum = a.substr(0,lmax-i-1) + sum;
	}
	return sum;
}

// returns true if s1 is greater than or equal to s2 else false
bool isGreater(string s1, string s2)
{
	int l = s1.length();
	f(i,l)
	{
		int a = getIntAt(s1,l-1-i);
		int b = getIntAt(s2,i);
		if(a > b)
			return true;
		else if(a < b)
			return false;
	}
	return true;
}

string reverse(string st)
{
	string n = "";
	int l = st.length();
	f(i,l)
		n = n + st[l-1-i];
	return n;
}

void print(string s, string a)
{
	int l = s.length();
	f(i,l)
	{
		printf("%c", s[i]);
	}
	f(i,a.length())
	{
		printf("%c",a[i] );
	}
	f(i,l)
	{
		printf("%c",s[l-1-i] );
	}
	printf("\n");
}
void getNextpalindrome(string st)
{
	int l = st.length();
	int mid = l/2 - 1;
	string m = "";
	int offset = 0;
	if(l%2 !=0)
	{
		m = m + st[mid+1];
		offset = 1;
	}
	string left = st.substr(0,mid+1);
	string right = st.substr(mid+1+offset);
	// string lrev = reverse(left);
	if(isGreater(left,right))
		print(left,m);
	else
	{
		int carry = 1;
		if(l%2 != 0)
		{
			int t = getIntAt(st,mid+1) + 1; //no at mid
			if(t<=9)
			{
				string a ="";
				a += (char)(t+48);
				print(left ,a);
				return;
			}
			else
				m = "0"; //carry will remain 1, t can at max be 10
		}
		string lnew = successor(left);
		print(lnew,m);
	}
}

int main()
{
	int k;
	cin>>k;
	int i;
	for(i=0;i<k;i++)
	{
		string st;
		cin>>st;
		getNextpalindrome(successor(st));
	}
	return 0;
}