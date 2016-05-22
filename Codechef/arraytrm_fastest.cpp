#include <iostream>
#include<limits.h>
 
using namespace std;
 
#define MAX 107
#define gc getchar_unlocked
 
///  For fast Input ....
inline void inp(int &x)
{
		register int c = gc();
		x = 0;
		int neg = 0;
		for(;((c<48 || c>57) && c != '-');c = gc());
		if(c=='-') {neg=1;c=gc();}
		for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
		if(neg) x=-x;
}
 
 
int main()
{
  int t,n,k,arr[MAX],ct;
register int i;
  int leave1,leave2,chance,rem;
 
inp(t);
  while (t>0)
    {
      inp(n);
      inp(k);
      for ( i=1;i<=n;i++ )
        inp(arr[i]);
 
      k++;
      chance = 0;
      rem = arr[1] %k ;
      leave1 = INT_MAX;
      leave2=INT_MAX;
      ct=0;
 
      while ( chance <=2 && ct<n-1)
        {
          ct=0;
          for ( i=1;i<=n ; i++ )
            {
              if ( chance ==1 && i == leave1 )
                continue;
 
              if ( chance ==2 && i==leave2 )
                continue;
 
              if ( rem != (arr[i]%k)  )
                {
 
                  if ( chance == 0 )
                    {
                      leave1 =1;
                      leave2=i;
                      rem = arr[i]%k;
                      break;
                    }
                  else
                    if ( chance == 1 )
                      {
                        rem =arr[1]%k;
                        break;
                      }
                }
              else
         ct++;
            }
          chance++;
        }
 
      if ( ct>=n-1 )
        printf("YES\n");
      else
        printf("NO\n");
      t--;
    }
  return 0;
}
 