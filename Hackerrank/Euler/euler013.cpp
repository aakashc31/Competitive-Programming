#include <iostream>
#include <string>
using namespace std;

//fuck yeah....!

int depth =0;
int getIntAt(string st, int i) //returns integer at any index i of string
{
	char ch = st[i];
	int asc = (int)ch;
	asc-=48;
	return asc;
}
string rippleCarryAdder(string a, string b) //makes the strings of equal length and adds them, returns actual value
{
	string max = (a.length()> b.length()) ? a:b;
	string min = (a.length()<=b.length())?a:b;
	int lmax = max.length();
	while(min.length()<lmax)
	{
		min = "0"+min;
	}
	string sum = "";
	int carry = 0;
	for(int i=0;i<lmax;i++)
	{
		int l1 = getIntAt(max,lmax-1-i);
		int l2 = getIntAt(min,lmax-1-i);
		int s = l1+l2+carry;
		carry = s/10;
		s = s%10;
	//	cout<<"carry = "<<carry<<" sum = "<<s<<endl;
		char last = (char)(s+48);
		sum = last + sum;
	}
	if(carry==1)
		sum = "1"+sum;
	return sum;
}

string subtractor(string a, string b) //subtracts b from a, assuming a and b are +ve and b<a
{
	int lmax = a.length();
	string max = a;
 	string min = b;
	string sub = "";
	int carry = 0;
	while(min.length()!=lmax)
	{
		min = "0"+min;
	}
	for(int i=0;i<lmax;i++)
	{
		int l1 = getIntAt(max,lmax-1-i);
		int l2 = getIntAt(min,lmax-1-i);
		int s = l1- l2 + carry;
		if(s<0)
		{
			s+=10;
			carry = -1;
		}
		else
		{
			carry = 0;
		}
		//cout<<"carry = "<<carry<<" sum = "<<s<<endl;
		char last = (char)(s+48);
		sub = last + sub;
	}
	if(carry == -1)
	{
		// yaha pe subtract kar de 10 ki ith power, answer aa jaega, mera man ni kar ra abi... 
		sub = "-"+sub;
	}
	return sub;

}

unsigned long getLong(string st) //returns the integer the string represents
{
	unsigned long ret = 0;
	for(int i=0;i<st.length();i++)
	{
		int d = getIntAt(st,i);
		ret = ret*10 + d;
	}
	return ret;
}

string toString(unsigned long a) //returns the string form of the integer
{
	// cout<<"Converting to String... "<<a<<endl;
	string st = "";
	while(a>0)
	{
		int d = a%10;
		a = a/10;
		char ch = (char)(d+48);
		st = ch+ st;
	}
	// cout<<"returning converted string..."<<st<<endl;
	return st;
}

string addZeroes(string st, int m)
{
	for(int i = 1; i<=m ; i++)
	{
		st+="0";
	}
	return st;
}
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}
string fastmultiply(string a, string b)
{
	makeEqualLength(a,b);
	//cout<<"Multiplying "<<a<<" "<<b<<endl;
	depth+=1;
	// cout<<"depth = "<<depth<<endl;
	string ret = "";

	//base case
	unsigned long anum, bnum;
	unsigned long maxlim = (1<<15)-1;
	if(a.length()<=8)
	{
		anum = getLong(a);
		bnum = getLong(b);
		if(anum<=maxlim && bnum<=maxlim)
		{
			// cout<<"maxlim = "<<maxlim<<endl;
			// cout<<"anum is: "<<anum << " bnum is: "<<bnum<<endl;
			unsigned long mul = anum * bnum;
			// cout<<"returning... "<<mul<<endl;
			// cout<<"ret......"<<endl;
			string toret =  toString(mul);
			return toret;
		}

	}


	//karatsuba
	int m = a.length()/2;
	string x0 = a.substr(m);
	string x1 = a.substr(0,m);
	string y0 = b.substr(m);
	string y1 = b.substr(0,m);


	string z2 = fastmultiply(x1,y1);
	// cout<<"z2 computed..."<<endl;
	//string z1 = rippleCarryAdder(fastmultiply(x1,y0), fastmultiply(y1,x0));
	string z0 = fastmultiply(x0,y0);
	// cout<<"z0 computed..."<<endl;
	string z1 = subtractor(fastmultiply(rippleCarryAdder(x1,x0), rippleCarryAdder(y1, y0)), rippleCarryAdder(z2,z0));
	// cout<<"z1 computed..."<<endl;
	m = a.length()-m;
	ret = rippleCarryAdder(rippleCarryAdder(addZeroes(z2, 2*m),z0), addZeroes(z1,m));
	// cout<<"returning.."<<ret<<endl;
	return ret;
}
string removePrecedingZeroes(string st)
{
	string ret = st;
	while(ret[0]=='0')
		ret  = ret.substr(1);
	return ret;
}
int main()
{
	
	int num_cases;
	cin>>num_cases;
	string ar[1000];
	for(int i=0; i<num_cases; i++)
	{
		cin >> ar[i];
		// string n1, n2;
		// cin>>n1;
		// cin>>n2;
		// string st = fastmultiply(n1,n2);
		// st = removePrecedingZeroes(st);
		// cout<<st<<endl;
	}

	string sum = ar[0];
	for(int i=1; i<num_cases; i++)
	{
		sum =  rippleCarryAdder(sum, ar[i]);
	}
	cout << sum.substr(0,10) << endl;
	return 0;
}

