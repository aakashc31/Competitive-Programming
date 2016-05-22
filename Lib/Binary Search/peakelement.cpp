// http://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
#include <bits/stdc++.h>
using namespace std;

int getPeakElement(int* ar, int len)
{
	if(len<3)
		return -1;
	int low = 1, high = len-2;
	while(low<high)
	{
		int mid = low + (high-low)/2;
		if(ar[mid])
	}
}