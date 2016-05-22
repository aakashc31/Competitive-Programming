#include <stdio.h>
#include <cstring>
#define f(i,n) for(lli i=0;i<n;i++)
typedef long long int lli;

class BigNumber
{
	lli num[100]; //array of lli's. Each will contain k digits
	int k = 9;
	int length; // this denotes the length of array
public:

	// this function converts ch[i..j] to integer
	lli convertToL(char ch[], int i, int j)
	{
		lli s=0;
		for(int k=i;k<=j;k++)
			s = s*10 + (ch[k] - '0');
		return s;
	}

	// this function will store the number in the string str, for further processing
	// divides str into slots of k length and stores them, the first k digits are stored at the last in the array
	BigNumber(char* str)
	{
		int l = strlen(str);
		num = new lli(l/k + 2);
		length = 0;
		while(true)
		{
			if(l<=k)
			{
				num[length] = convertToL(str,0,l-1);
				length++;
				break;
			}
			else
			{
				num[length] = convertToL(str,l-k,l-1);
				length++;
				l-=k;
			}
		}
		l = length;
		while(l < 100)
			num[l++] = 0;
	}

	// prints preceding zeroes
	void printInTen(lli a)
	{
		int len = log10(a);
		len++;
		// len is then number of digits in a
		f(i,10-len)
			printf("0");
		printf("%lld",a);
	}

	//print the number 
	void printNumber()
	{
		bool flag = true;
		int len = length-1;
		while(len>=0)
		{
			if(flag)
			{
				printf("%lld",num[len--]);
				flag = false;
				continue;
			}
			printf("%lld",num[len--]); //this is an error... preceding zeroes in the segments will not be printed.
		}
		printf("\n");
	}

	int getLength()
	{
		return length;
	}

	void add(BigNumber b)
	{
		int l2 = b.getLength();
		int lres = max(l1,length) + 1;
		lli sum[lres];

	}
};

int main()
{
	BigNumber b("798798707");
	b.printNumber();
	printf("%d\n",b.getLength());
	return 0;
}