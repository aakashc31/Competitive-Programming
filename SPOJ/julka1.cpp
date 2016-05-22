#include <iostream>
#include <stdio.h>
#include <cstring>
#define f(i,n) for(int i=0;i<n;i++)


void compute_klaudia(int total[120],int l1, int diff[120], int l2)
{
	while(l1<120)
		total[l1] = 0, l1++;
	while(l2<120)
		total[l2] = 0, l2++;
	printf("Printing total..\n");
	f(i,120)
		printf("%d",total[119-i]);
	int sum[120];
	f(i,120) sum[i]=0;

	int carry = 0;
	f(i,120)
	{
		int s = diff[i] + total[i] + carry;
		sum[i] = s%10;
		carry = s/10;
	}
	int l = 119;
	while(sum[l]==0)
		l--;
	printf("Printing sum..\n");
	while(l>=0)
	{
		printf("%d",sum[l--]);
	}
	printf("\n");
	// div sum by 2
	carry = 0;
	f(i,120)
	{
		if(sum[i] <= 1)
		{
			carry = sum[i];
			sum[i] = 0;
		}
		else
		{
			int s = (carry*10 + sum[i])/2;
			carry = sum[i]%2;
			sum[i] = s;
		}
	}

	l=119;
	while(sum[l]==0)
		l--;
	while(l>=0)
	{
		printf("%d",sum[l--]);
	}
	printf("\n");
}

int main()
{
	char n[120]; //total number of apples
	char k[120]; //difference
	int t=10; //test cases
	int total[120];
	int diff[120];
	while(t--)
	{
		scanf("%s",n);
		printf("%s\n",n);
		scanf("%s",k);
		int l1 = strlen(n);
		int l2 = strlen(k);
		f(i,l1)
			total[l1-1-i] = n[i] - '0';
		f(i,l2)
			diff[l2-1-i] = k[i]-'0';
		f(i,l1)
			printf("%d",total[l1-1-i]);
			printf("\n");
		f(i,l2)
			printf("%d",diff[l2-1-i]);
			printf("\n");
		compute_klaudia(total,l1,diff,l2);
		// compute_natalia(total,l1,diff,l1);
	}
	return 0;

}