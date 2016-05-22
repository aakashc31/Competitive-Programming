#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
// #define get(n) scanf("%d",&n)
struct node
{
	char a[5];
	int circ[12];
}ar[800000];

struct nm
{
	int a; //current mode
	int lazy; //laziness
	int arr[12]; //this stores maximum in a particular range for all the 12 permutations this can have.
}segment_tree[16000000];

inline void get( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

void print()
{
	f(i,5)
	{
		printf("\n");
		printf("segment_tree[%d].a = %d\n",i,segment_tree[i].a);
		printf("segment_tree[%d].lazy = %d\n",i,segment_tree[i].lazy);
		printf("arr:\n");
		f(j,12)
		{
			printf("%d, ",segment_tree[i].arr[j]);
		}
		printf("\n");
	}
}

void rotate(char ch[5], int l)
{
	char c = ch[0];
	for(int j=l-1; j>=0;j--)
	{
		char temp = ch[j];
		ch[j] = c;
		c = temp;
	}
}

int toInt(char ch[5], int i, int j)
{
	int r=0;
	for(int k=i;k<=j;k++)
	{
		r = r*10 + (ch[k]-'0');
	}
	return r;
}

void create_all_circular_perm(char a[5], int ar[12])
{
	int l = strlen(a);
	f(i,l)
	{
		ar[i] = toInt(a,0,l-1);
		rotate(a,l);
	}
	int p=12/l;
	int offset = l;
	f(i,p-1)
	{
		f(j,l)
		{
			ar[offset+j] = ar[j];
		}
		offset+=l;
	}
}

void toCharArray(char ch[5], int num)
{
	if(num==0)
	{
		ch[0] = '0';
		ch[1] = '\0';
		return;
	}
	int i=0;
	while(num>0)
	{
		ch[i] = (num%10)+'0'; num/=10; i++;
	}
	ch[i]='\0';
	int j=0;i--;
	while(j<=i)
	{
		char c = ch[i];
		ch[i] = ch[j];
		ch[j] = c;
		i--,j++;
	}
}

void initiate(int i, int l, int r)
{
	int mid = (l+r)/2;
	if(l==r)//base case
	{
		segment_tree[i].a= segment_tree[i].lazy = 0;
		f(j,12)
			segment_tree[i].arr[j] = ar[l].circ[j];
	}
	else
	{
		initiate(2*i+1,l,mid);
		initiate(2*i+2,mid+1,r);
		segment_tree[i].a= segment_tree[i].lazy = 0;
		f(j,12)
			segment_tree[i].arr[j] = max(segment_tree[2*i+1].arr[j],segment_tree[2*i+2].arr[j]);
	}
}

// input height array
void input(int& n)
{
	int k;
	get(n);
	f(i,n)
	{
		get(k);
		toCharArray(ar[i].a,k);
		create_all_circular_perm(ar[i].a,ar[i].circ);
	}
	initiate(0,0,n-1);
	//print();
}

// i is current node, il is left, ir is right, from to to is the current range
void update(int i, int il, int ir, int from, int to, int f)
{
	int laztmp = (segment_tree[i].lazy);
	if(laztmp!=0)
	{
		// printf("Lazy caught %d\n",i );
		segment_tree[i].lazy=0;
		segment_tree[i].a = (segment_tree[i].a + laztmp);
		// pass laziness on to children
		if(il<ir)
		{
			segment_tree[2*i+1].lazy+=laztmp;
			segment_tree[2*i+2].lazy+=laztmp;
		}
	}
	if(il>to || ir<from) //not in range
		return;
	else if(il>=from && ir<=to) //completely in range
	{
		// printf("In range\n");
		segment_tree[i].a+=f;
		if(il<ir)
		{
			segment_tree[2*i+1].lazy+=f;
			segment_tree[2*i+2].lazy+=f;
		}
	}
	else
	{
		int mid = (il+ir)/2;
		update(2*i+1,il,mid,from,to,f);
		update(2*i+2,mid+1,ir,from,to,f);
		segment_tree[i].a = 0;
		f(j,12)
			segment_tree[i].arr[j] = max(segment_tree[2*i+1].arr[(j+segment_tree[2*i+1].a)%12],segment_tree[2*i+2].arr[(j+segment_tree[2*i+2].a)%12]);
	}
	
}

int query(int i, int il, int ir, int from, int to)
{
	int laztmp = (segment_tree[i].lazy);
	if(laztmp!=0)
	{
		segment_tree[i].lazy=0;
		segment_tree[i].a = (segment_tree[i].a + laztmp)%12;
		// pass laziness on to children
		if(il<ir)
		{
			segment_tree[2*i+1].lazy+=laztmp;
			segment_tree[2*i+2].lazy+=laztmp;
		}
	}
	if(il>to || ir<from)
		return 0;
	else if(il>=from && ir<=to)
		return segment_tree[i].arr[segment_tree[i].a%12];
	else
	{
		int mid = (il+ir)/2;
		return max(query(2*i+1,il,mid,from,to),query(2*i+2,mid+1,ir,from,to));
	}
}

int main()
{
	int n;
	input(n);
	int q,ch,l,r,f;
	get(q);
	while(q--)
	{
		get(ch);
		if(ch==0)
		{
			get(l), get(r), get(f);
			update(0,0,n-1,l,r,f);
		}
		else
		{
			get(l), get(r);
			printf("%d\n",query(0,0,n-1,l,r));
		}
	}
	return 0;
}