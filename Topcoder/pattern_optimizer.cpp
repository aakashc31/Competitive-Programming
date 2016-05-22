#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n;i++)

class PatternOptimizer
{
public:
	string optimize(string pattern);
};

string PatternOptimizer::optimize(string pattern)
{
	int l = pattern.length();
	f(i,l)
	{
		if(pattern[i]=='?'||pattern[i]=='*')
		{
			int beg = i;
			while(i<l && (pattern[i]=='?'||pattern[i]=='*'))
				i++;
			string reg = pattern.substr(beg,i-beg);
			string temp = "";
			bool flag = false; //true if * appears
			f(j,reg.length())
			{
				if(reg[j]=='?')
					temp+="?";
				else
					flag = true;
			}
			if(flag)
				temp = "*"+temp;
			pattern.replace(beg,i-beg,temp);
			i = beg+temp.length();
			l = pattern.length();
		}
	}
	return pattern;
}

int main()
{
	PatternOptimizer p;
	string s = "T***nd?*";
	s = p.optimize(s);
	cout << s <<endl;
	return 0;
}

/*Problem Statement
    
Some dictionaries use a word pattern that consists of letters, '?' symbols which each denote exactly one letter, and '*' symbols which each denote zero or more letters.
Interestingly, some patterns represent the same set of words. For example, "*??*a" and "?*?a" (quotes for clarity only) patterns both represent all words that consist of three or more letters and end with 'a'.
You will be given a string pattern. Your method should return the shortest pattern that represents the same set of words as the given pattern. Return the lexicographically first in case of tie.
Definition
    
Class:
PatternOptimizer
Method:
optimize
Parameters:
string
Returns:
string
Method signature:
string optimize(string pattern)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Notes
-
Note that '*' comes before '?' in the lexicographical order.
Constraints
-
pattern will contain between 1 and 50 characters, inclusive.
-
pattern will contain only letters ('a'-'z', 'A'-'Z'), '?' and '*'.
Examples
0)

    
"*??*a"
Returns: "*??a"

1)

    
"*b**a*"
Returns: "*b*a*"

2)

    
"cla??"
Returns: "cla??"

3)

    
"*?*?*?*"
Returns: "*???"

4)

    
"T***nd?*"
Returns: "T*nd*?"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.*/