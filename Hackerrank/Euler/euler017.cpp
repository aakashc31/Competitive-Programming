#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

void print1dig(int n)
{
	switch(n)
	{
		case 1:
			printf("One ");
			break;
		case 2:
			printf("Two ");
			break;
		case 3:
			printf("Three ");
			break;	
		case 4:
			printf("Four ");
			break;
		case 5:
			printf("Five ");
			break;
		case 6:
			printf("Six ");
			break;
		case 7:
			printf("Seven ");
			break;
		case 8:
			printf("Eight ");
			break;
		case 9:
			printf("Nine ");
			break;
	}
}

void print_tens(int n)
{
	if(n/10 == 1)
	{
		switch(n)
		{
			case 10:
				printf("Ten ");
				break;
			case 11:
				printf("Eleven ");
				break;
			case 12:
				printf("Twelve ");
				break;
			case 13:
				printf("Thirteen ");
				break;
			case 14:
				printf("Fourteen ");
				break;
			case 15:
				printf("Fifteen ");
				break;
			case 16:
				printf("Sixteen ");
				break;
			case 17:
				printf("Seventeen ");
				break;

			case 18:
				printf("Eighteen ");
				break;

			case 19:
				printf("Nineteen ");
				break;
		}
		return;
	}
	switch(n/10)
	{
		case 2:
			printf("Twenty ");
			break;
		case 3:
			printf("Thirty ");
			break;
		case 4:
			printf("Forty ");
			break;
		case 5:
			printf("Fifty ");
			break;
		case 6:
			printf("Sixty ");
			break;
		case 7:
			printf("Seventy ");
			break;
		case 8:
			printf("Eighty ");
			break;
		case 9:
			printf("Ninety ");
			break;
	}
}
void print3digs(int n)
{
	if(n<10)
		print1dig(n);
	else if(n<20)
		print_tens(n);
	else if(n<100)
		print_tens(n), print1dig(n%10);
	else
		print1dig(n/100), printf("Hundred "), print3digs(n%100);
}
int convertToNum(char ch[15], int l, int r)
{
	int ret = 0;
	while(l<=r)
	{
		ret = ret*10 + (ch[l]-'0');
		l++;
	}
	return ret;
}

int main()
{
	int t;
	char ch[15];
	getNum(t);
	while(t--)
	{
		scanf("%s",ch);
		int l = strlen(ch);
		if(l==1 && ch[0]=='0')
			printf("Zero");
		else if(l<=3)
		{
			print3digs(convertToNum(ch,0,l-1));
		}
		else if(l<=6)
		{
			print3digs(convertToNum(ch,0,l-4));
			printf("Thousand ");
			print3digs(convertToNum(ch,l-3,l-1));
		}
		else if(l<=9)
		{
			print3digs(convertToNum(ch,0,l-7));
			printf("Million ");
			int t = convertToNum(ch,l-6,l-4);
			print3digs(t);
			if(t!=0)
				printf("Thousand ");
			print3digs(convertToNum(ch,l-3,l-1));
		}
		else if(l<=12)
		{
			print3digs(convertToNum(ch,0,l-10));
			printf("Billion ");

			int t = convertToNum(ch,l-9,l-7);
			print3digs(t);
			if(t!=0)
				printf("Million ");
			
			t = convertToNum(ch,l-6,l-4);
			print3digs(t);
			if(t!=0)
				printf("Thousand ");
			print3digs(convertToNum(ch,l-3,l-1));
		}
		else
		{
			printf("One Trillion");
		}
		printf("\n");
	}
	return 0;
}