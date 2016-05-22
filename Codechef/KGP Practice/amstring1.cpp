#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)
typedef long long int lli;

int compute(int* ar, int len, int k)
{
	// f(i,len) printf("%d ",ar[i]);
	// printf("\n");
	int ans = 0, temp;
	for(int i=1; i<len; i++)
	{
		temp = lower_bound(ar,ar+i,ar[i]-k)-ar;
		temp = i - temp;
		ans+=temp;
	}
	// printf("returning - %d\n\n", ans);
	return ans;
}

char A[1005], B[1005];

int main()
{
	int T,N,K,i,j,k;
	g(T);
	for(int t=0;t<T;t++)
	{
		g(N), g(K);
		scanf("%s",A);
		scanf("%s",B);
		int comp[N][N];
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(A[i]==B[j])
					comp[i][j]=1;
				else
					comp[i][j]=0;
			}
		}
		int ans=0;
		for(i=N-1;i>=0;i--){
			int presum[N-i+1];int sum=0;
			for(j=0;j<N;j++){
				if(i+j>=N)
					break;
				sum+= (1-comp[j][i+j]);
				presum[j+1]=sum;
			}
			presum[0]=0;
			ans+=compute(presum,N-i+1,K);
		}
		for(i=1;i<N;i++){
			int presum[N-i+1];int sum=0;
			for(j=0;j<N;j++){
				if(i+j>=N)
					break;
				sum+=(1 - comp[i+j][j]);
				presum[j+1]=sum;
				}
				presum[0] = 0;
				ans+=compute(presum,N-i+1,K);
			}
         
         printf("%d\n",ans);

	}
}