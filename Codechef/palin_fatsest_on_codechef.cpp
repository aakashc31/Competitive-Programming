#include<iostream>
#include<math.h>
#include<stdio.h>
#define x getchar_unlocked()
#define y putchar_unlocked
//http://www.algorithmist.com/index.php/SPOJ_PALIN
using namespace std;
int main() {
	int t,i,j,k,sym=0;
	scanf("%d\n",&t);
	char ch;
	while(t--) {
		sym=0;
		char A[1000010];
		ch=x;//cout<<ch<<endl<<"yo\n";
		for(i=0;ch!='\n';i++)
			A[i]=ch,ch=x;//cout<<ch;
		A[i]='\0';
		//cout<<"yea\n";
		for(j=i/2,k=(i-1)/2;j<i;j++,k--) {
			if(A[j]<A[k])break;
			if(A[j]>A[k]) {
				j=i;
				break;
				}
			}
		//cout<<j<<" "<<i<<endl;
		if(j!=i) {
		 	for(j=0;j<(i+1)/2;j++)
				y(A[j]);
			if(i%2==1) j-=2;
			else j--;
			for(;j>=0;j--)
				y(A[j]);
			y('\n');
			}
		else {
			j=(i-1)/2;
			if(j==0) {
				if(A[j]<'9') {
					A[j]++;
					while(i--)
						y(A[j]);
					}
				else {
					if(i==2) printf("101");
					else printf("11");
					}
				}
			else {
			for(;j>0;j--) {
				if(A[j]<'9') 
					{A[j]++;break;}
				else 
					A[j]='0';
				}
			if(j==0 & A[j]=='9') sym=1,A[j]='0',y('1');
			else if(j==0) A[j]++;
			else ;
			if(sym==1) {
				
				for(j=0;j<(i+1)/2;j++)
					y(A[j]);
				if(i%2==1) j-=2;
				else j--;
				for(;j>0;j--)
					y(A[j]);
				y('1');
				}
			else {
				
				for(j=0;j<(i+1)/2;j++)
					y(A[j]);
				if(i%2==1) j-=2;
				else j--;
				for(;j>=0;j--)
					y(A[j]);
				}
			}
			y('\n');		
			}
		}
	return 0;
	}