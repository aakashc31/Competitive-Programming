#include <stdio.h>

//when submitting change getchar() -> getchar_unlocked(), putchar -> putchar_unlocked 
#define inpch getchar()
#define outch putchar

class Input
{
public:
	int inputInteger()
	{
		char ch = inpch;
		int r=0;
		while(ch!='\n')
		{
			r = r*10 + ch-'0';
			ch = inpch;
		}
		return r;
	}

	void inputString(char* str)
	{
		char ch = inpch;
		int i=0;
		while(ch!='\n')
			str[i++] = ch, ch=inpch;
		str[i] = '\0';
	}
};

class Output
{
public:
	void printString(char* str)
	{
		int i=0;
		while(str[i]!='\0')
			outch(str[i++]);
	}
};