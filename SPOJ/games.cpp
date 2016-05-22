#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	
	int a = 1<<31;
	int p = 0;
	if(p&a)
		printf("Negative\n");
	else
		printf("Non negative\n");
	printf("%d\n", a);
	return 0;
}