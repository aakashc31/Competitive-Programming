// Adrian Kosowski, 2004
 
#include <stdio.h>
 
#define BASE 1000000000
 
const long len = 10;
 
class giantint
{
private:
	int val[len];
 
 
public:
   giantint (int num)
   {
		for (int i=1; i<len; i++)
			val[i]=0;
		val[0]=num;
   };
   
   void mul(int num)
   {
		int rem = 0;
		for (int i=0; i<len; i++)
		{
			long long res = (long long)val[i]*num+rem;
			val[i]=res%BASE;
			rem=res/BASE;
		}
   }
 
   void div(int num)
   {
		int rem = 0;
		for (int i=len-1; i>=0; i--)
		{
			long long res = (long long)val[i]+(long long)BASE*rem;
			rem = res%num;
			val[i]=res/num;
		}
   }
 
   void print (void) {
      long flag=0;
      for (long i=len-1; i>=0; i--) {
         if (!flag && val[i]) printf("%d", val[i]);
           if (flag)
             printf("%09d", val[i]);
         if (val[i]) flag=1;
      }
      if (!flag) printf("0");
   };
 
};
 
///////////////////////////////////////////////////////////////////////////////
 
 
int main (void)
{
    int t;
	scanf ("%d", &t);
	while (t--)
	{
		int n, k;
		scanf ("%d%d", &n, &k);
		n--;
		k--;
		if (k<=n/2) k=n-k;
		giantint p(1);
		for (int i=k+1; i<=n; i++)
			p.mul(i);
		for (int i=2; i<=n-k; i++)
			p.div(i);
		p.print();
        printf("\n");
	}
}
 