#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n;i++)

class RegimentArming
{
public:
	int getMax(vector <int> counts, vector <int> powers, int N, int i);
	int chooseGuns(vector <int> counts, vector <int> powers, int N);
};

int RegimentArming::getMax(vector <int> counts, vector <int> powers, int N, int i)
{
	int sleft = 0;
	int icpy = i, ncpy = N;
	while(N>0)
	{
		if(counts[i]<N)
		{
			N-=counts[i];
			sleft+= counts[i]*powers[i];
			i--;
		}
		else
		{
			sleft += N*powers[i];
			break;
		}
		if(i<0 && N>0)
		{
			sleft = -1;
			break;
		}
	}

	i=icpy, N = ncpy;
	int sright = 0;
	while(N>0)
	{
		if(counts[i] < N)
		{
			sright += counts[i]*powers[i];
			N-=counts[i];
			i++;
		}
		else
		{
			sright += N*powers[i];
			break;
		}
		if(i==counts.size() && N>0)
		{
			sright = -1;
			break;
		}
	}

	return (max(sright, sleft));

}
int RegimentArming::chooseGuns(vector <int> counts, vector <int> powers, int N)
{
	int ret = 0;
	int n = counts.size();
	f(i,n)
	{
		int rtemp = getMax(counts, powers, N, i);
		if(rtemp>ret)
			ret = rtemp;
	}
	return ret;
}

int main()
{
	int c[] = {5,37,4};
	int p[] = {7,4,8};
	vector<int> count(c,c+3);
	vector<int> power(p,p+3);
	RegimentArming reg;
	int r = reg.chooseGuns(count, power,20);
	printf("%d\n",r);
	return 0;
}