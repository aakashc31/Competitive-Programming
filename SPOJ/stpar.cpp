#include <stdio.h>
#include <stack>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int n;
	getNum(n);
	while(n!=0)
	{
		stack<int> mystack;
		int next = 1;
		f(i,n)
		{
			int temp;
			getNum(temp);
			if(temp==next)
			{
				next++;
			}
			else
			{
				while(!mystack.empty() && mystack.top()==next)
				{
					// printf("popping... %d \n",next);
					mystack.pop(); next++;
				}
				// printf("pushing.. %d\n",temp);
				mystack.push(temp);
			}
		}
		if(mystack.empty())
			printf("yes\n");
		else
		{
			int t = mystack.top();
			mystack.pop();
			// printf("popping... %d \n",t);
			bool flag=true;
			while(!mystack.empty())
			{
				if(t < mystack.top())
				{
					t = mystack.top(); mystack.pop();
					// printf("popping... %d \n",t);
				}
				else
				{
					flag = false;
					break;
				}
			}
			if(flag)
				printf("yes\n");
			else 
				printf("no\n");
		}
		
		getNum(n);
	}
}