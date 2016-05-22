//finally... fuck yeah!!!
#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
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

bool isGreater(char ch[1000000], int lend, int lbeg, int rbeg, int rend) //returns false if equal
{
	for(int i=0; i<=rend-rbeg; i++)
	{
		if(ch[lbeg-i]> ch[rbeg+i])
			return true;
		else if(ch[lbeg-i] == ch[rbeg+i])
			continue;
		else
			return false;
	}
	return false;
}

void print_ans(char ch[1000000], int low, int high)
{
	for(int i=low; i<=high;i++)
		printf("%c",ch[i]);
	for(int i=low; i<=high;i++)
		printf("%c",ch[high-i]);
}

void print_ans_odd(char ch[1000000], int low, int high, char c)
{
	for(int i=low; i<=high;i++)
		printf("%c",ch[i]);
	printf("%c",c);
	for(int i=low; i<=high;i++)
		printf("%c",ch[high-i]);
}

void print_succeded_ans(char ch[1000000], int low, int high)
{
	int carry = 1;
	// mind the increase in num of digits
	for(int i=high; i>=low;i--)
	{
		if(ch[i]=='9')
		{
			ch[i] = '0';
			carry = 1;
		}
		else
		{
			ch[i]++;
			carry = 0;
			break;
		}
	}
	if(carry==1)
	{
		printf("1");
		int numZeroes = 2*(high-low+1)-1;
		f(i,numZeroes)
			printf("0");
		printf("1");
	}
	else print_ans(ch,low,high);
}

void print_succeded_ans_odd(char ch[1000000], int low, int high)
{
	int carry = 1;
	// mind the increase in num of digits
	for(int i=high; i>=low;i--)
	{
		if(ch[i]=='9')
		{
			ch[i] = '0';
			carry = 1;
		}
		else
		{
			ch[i]++;
			carry = 0;
			break;
		}
	}
	if(carry==1)
	{
		printf("1");
		int numZeroes = 2*(high-low+1);
		f(i,numZeroes)
			printf("0");
		printf("1");
	}
	else print_ans_odd(ch,low,high,'0');
	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-- > 0)
	{
		char str[1000000];
		scanf("%s",str);
		int len = strlen(str);
		if(len%2 == 0) //if even number of digits
		{
			//if reverse of left half is greater than right then left+rev(left) else successor of left and it's rev
			if(isGreater(str,0,len/2 -1,len/2,len-1))
			{
				print_ans(str,0,len/2-1); //prints str[0..len/2-1] and its reverse
			}
			else
			{
				print_succeded_ans(str,0,len/2-1); //takes successor of str[0..len/2-1] and prints it+reverse(it)
			}
		}
		else
		{
			char ch = str[len/2];
			if(isGreater(str,0,len/2 -1,len/2+1,len-1))
			{
				print_ans_odd(str,0,len/2-1,ch); //prints str[0..len/2-1] + 'ch' + its reverse
			}
			else if(ch<'9')
			{
				print_ans_odd(str,0,len/2-1,ch+1); //prints str[0..len/2-1] + 'ch+1' + its reverse
			}
			else
			{
				print_succeded_ans_odd(str,0,len/2-1); //takes successor of str[0..len/2-1] and prints it+'0'+reverse(it)
			}
		}
		printf("\n");
	}
	return 0;
}