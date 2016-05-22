#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n ;i++)
#define g(n) scanf("%d",&n)
#define pb push_back
typedef vector<int> vi;

bool isPalin(const vi& v)
{
	int l = v.size();
	f(i,l)
	{
		if(v[i]!=v[l-i-1])
			return false;
	}
	return true;
}

vi addRev(const vi& v)
{
	vi ret(0);
	int l = v.size();
	int carry = 0,k;
	f(i,l)
	{
		k = (v[i])+(v[l-i-1])+carry;
		ret.pb(k%10);
		carry = k/10;
	}
	return ret;
}

int get(const vi& v)
{
	if(v.size()>=7)
		return 0;
	int k=0;
	f(i,v.size())
		k = k*10 + v[v.size()-i-1];
	if(k<=100000)
		return k;
	return 0;
}

int ar[100001];
void set_ar(int n)
{
	vi num(0);
	while(n>0){
		num.pb(n%10);
		n/=10;
	}
	if(isPalin(num))
		ar[get(num)]++;
	else
	{
		int ct = 0;
		while(ct<=60){
			ct++;
			num = addRev(num);
			if(isPalin(num)){
				ar[get(num)]++;
				return;
			}
		}
	}
}
int main()
{
	memset(ar,0,sizeof ar);
	for(int i=1; i<=100000; i++){
		set_ar(i);
	}
	printf("%d\n",ar[121]);
	return 0;
}