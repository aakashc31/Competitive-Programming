#include <iostream>
#include <time.h>
using namespace std;

int allPrimes[9592];
void sieve(int a, int max)
{
	bool* isPrime = new bool[max+1];
	for(int j=2; j<=max;j++)
		isPrime[j] = true;
	isPrime[0] = isPrime[1] = false;
	for(int j = 2; j<=max; j++)
	{
		if(!isPrime[j])
			continue;
		unsigned long k = j*j;
		for( ; k<=max; k+=j)
		{
			isPrime[k] = false;
		}		
	}
	int tr = 0;
	for(int l = a; l<=max; l++)
	{
		if(isPrime[l])
		{
			allPrimes[tr] = l;
			tr++;
		}
	}
	// cout << "tr = "<<tr<<endl<<allPrimes[0]<<endl;
}

int main()
{
	int testcases = 0;
	cin>>testcases;
	sieve(1,100000);
	while(testcases>0)
	{
		int ub,lb;
		cin>>lb;
		cin>>ub;

		if(lb==1)
			lb++;
		if(ub <= 100000)
		{
			int j = 0;
			for(j=0; j<9592;j++)
			{
				if(lb<=allPrimes[j])
				{
					break;
				}
			}
			while(allPrimes[j] <= ub && j<9592)
			{
				cout << allPrimes[j] <<endl;
				j++;
			}
		}
		else if(lb > 100000)
		{
			int len = ub-lb+1;
			bool checkPrimes[len];
			bool init = true;
			if(lb%2==0)
				init = false;
			for(int i=0;i<len;i+=2)
			{
				checkPrimes[i] = init;
			}
			init = !init;
			for(int i=1;i<len;i+=2)
			{
				checkPrimes[i] = init;
			}

			int st_index = (lb%2==0)?1:0;
			
			//iterating on all odd numbers
			for(;st_index<len; st_index+=2)
			{
				if(checkPrimes[st_index])
				{
					for(int k = 1; k<9592; k++)
					{
						int kthprime = allPrimes[k];
						if(kthprime*kthprime > (lb + st_index))
							break;
						if((lb+st_index)%allPrimes[k]==0)
						{
							int a = st_index;
							// int kthprime = allPrimes[k];
							while(a < len)
							{
								checkPrimes[a] = false;
								a += kthprime;
							}
						}
						else
						{
							//do nothing
						}
					}
				}
			}

			for(int i = 0; i < len; i++)
			{
				if(checkPrimes[i])
					cout << lb+i << endl;
			}

		}

		else
		{
			//this means lb < 100000 and ub > 100000
			int j = 0;
			for(j=0; j<9592;j++)
			{
				if(lb<=allPrimes[j])
				{
					break;
				}
			}

			while(j<9592)
			{
				cout << allPrimes[j] << endl;
				j++;
			}
			lb = 100000;
			int len = ub-lb+1;
			bool checkPrimes[len];
			bool init = true;
			if(lb%2==0)
				init = false;
			for(int i=0;i<len;i+=2)
			{
				checkPrimes[i] = init;
			}
			init = !init;
			for(int i=1;i<len;i+=2)
			{
				checkPrimes[i] = init;
			}

			int st_index = (lb%2==0)?1:0;
			
			//iterating on all odd numbers
			for(;st_index<len; st_index+=2)
			{
				if(checkPrimes[st_index])
				{
					for(int k = 1; k<9592; k++)
					{
						int kthprime = allPrimes[k];
						if(kthprime*kthprime > (lb + st_index))
							break;
						if((lb+st_index)%allPrimes[k]==0)
						{
							int a = st_index;
							// int kthprime = allPrimes[k];
							while(a < len)
							{
								checkPrimes[a] = false;
								a += kthprime;
							}
						}
						else
						{
							//do nothing
						}
					}
				}
			}

			for(int i = 0; i < len; i++)
			{
				if(checkPrimes[i])
					cout << lb+i << endl;
			}
		}

		cout << endl;
		testcases--;
	}
	return 0;
}