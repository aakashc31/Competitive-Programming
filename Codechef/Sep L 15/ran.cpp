#include<iostream>
using namespace std;
int main()
{
int t,n,k;
{
cin>>n>>k;
int a[n+1],pos[n+1];
for(int i=1;i<=n;i++)
{
cin>>a[i];
pos[a[i]]=i; //position of a[i] will be i
}
for(int i=1;i<=n;i++)
{
if(!k) //no more swapping can be done
break;
else
{
if(???)
{
k--;
int temp = a[i]; //swapping a[i] with n-i+1
a[i] = n-i+1;
a[pos[n-i+1]] = temp;
pos[temp] = pos[n-i+1]; //swapping a[i]'s and a[n-i+1]'s positions
pos[n-i+1] = i;
}
}
}
for(int i=1;i<=n;i++) //output array after swapping is done
cout<<a[i]<<" ";
}

}
