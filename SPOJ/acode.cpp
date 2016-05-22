#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)
#define getStr(s) scanf("%s",s)

int main()
{
	char ch[5010];
	getStr(ch);
	while(ch[0]!='0')
	{
		int l = strlen(ch);
		if(l<=1)
			printf("1\n");
		else
		{
			long long int a = 1, b = 1; //a is T(n-2), b is T(n-1)
			int ind = 1;
			while(ind<=l)
			{
				//ind-1 is the next char
				if(ch[ind-1]=='0') {
					swap(a,b);
				}
				else if(ch[ind-1]>= '1' && ch[ind-1]<='6'){
					if(ind>=2 && (ch[ind-2]=='1' || ch[ind-2]=='2')) {
						long long int temp = b+a;
						a = b;
						b = temp;
					}
					else
					{
						a=b;
					}
				}
				else{
					if(ind>=2 && ch[ind-2]=='1') {
						long long int temp = b+a;
						a = b;
						b = temp;
					}
					else
					{
						a=b;
					}
				}
				ind++;
			}
			printf("%d\n",b);
		}
		getStr(ch);
	}
	return 0;
}