#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n;i++)

class AccessChanger
{
public:
	vector<string> convert(vector<string> program);
};


vector<string> AccessChanger::convert(vector<string> program)
{
	int l = program.size();
	vector<string> ret(0);
	f(i,l)
	{
		string line = program[i];
		size_t comment_index = line.find("//");
		if(comment_index==string::npos)//there are no comments
		{
			size_t arrow_index = line.find("->");
			while(arrow_index!=string::npos)
			{
				line.replace(arrow_index,2,".");
				arrow_index = line.find("->");
			}
		}
		else
		{
			size_t arrow_index = line.find("->");
			while(arrow_index!=string::npos && arrow_index<comment_index)
			{
				line.replace(arrow_index,2,".");
				arrow_index = line.find("->");
				comment_index = line.find("//");
			}
		}
		ret.push_back(line);
	}
	return ret;
}

int main()
{
	AccessChanger a;
	vector<string> v(0);
	v.push_back("aa->aa->//.->;");
	vector<string> s = a.convert(v);
	cout << s[0]<<endl;
}


/*Problem Statement
    
You are converting old code for a new compiler version. Each "->" string should be replaced by ".", but this replacement shouldn't be done inside comments. A comment is a string that starts with "//" and terminates at the end of the line.
You will be given a vector <string> program containing the old code. Return a vector <string> containing the converted version of the code.
Definition
    
Class:
AccessChanger
Method:
convert
Parameters:
vector <string>
Returns:
vector <string>
Method signature:
vector <string> convert(vector <string> program)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
program will have between 1 and 50 elements, inclusive.
-
Each element of program will contain between 1 and 50 characters, inclusive.
-
Each character in program will have ASCII value between 32 and 127, inclusive.
Examples
0)

    
{"Test* t = new Test();", 
 "t->a = 1;", 
 "t->b = 2;", 
 "t->go(); // a=1, b=2 --> a=2, b=3"}
Returns: 
{"Test* t = new Test();",
 "t.a = 1;",
 "t.b = 2;",
 "t.go(); // a=1, b=2 --> a=2, b=3" }

1)

    
{"---> // the arrow --->",
 "---",
 "> // the parted arrow"}
Returns: {"--. // the arrow --->", "---", "> // the parted arrow" }

2)

    
{"->-> // two successive arrows ->->"}
Returns: {".. // two successive arrows ->->" }

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.*/