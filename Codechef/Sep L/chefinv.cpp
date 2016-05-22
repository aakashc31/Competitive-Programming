#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) inp(n) //scanf("%d",&n)
#define getcx getchar//_unlocked

inline void inp( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

struct node
{
	int* ar; //sorted array
	int len; //length of the array ar
}segment_tree[16000000];

int ar[200000];
int br[200000];
int array_size;

int* merge_two_sorted_arrays(int* L, int n1, int* R, int n2)
{
    int i, j, k;
    int* arr = new int[n1+n2];
    i=j=k=0;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return arr;
}
//indexing will be 1 based
// ar of length l, index i to be stored in segment tree
void create_segment_tree(int* ar, int beg, int end, int i)
{
	int length = end-beg+1;
	if(length==1)
	{
		node t;
		int* temp = new int[1];
		temp[0] = ar[beg];
		t.ar = temp;
		t.len = length;
		segment_tree[i] = t;
		return;
	}
	// if not, then recursion
	int mid = (beg+end)/2;
	int fhalf = mid-beg+1;
	create_segment_tree(ar,beg,mid,2*i);
	create_segment_tree(ar,mid+1,end,2*i+1);
	int* merged = merge_two_sorted_arrays(segment_tree[2*i].ar, fhalf, segment_tree[2*i+1].ar, length-fhalf);
	node t;
	t.ar = merged;
	t.len = length;
	segment_tree[i] = t;
}

// returns the number of elements in ar[0..len] smaller than n, given ar is sorted
int num_smaller_elements(int* ar, int len, int n)
{
	if(ar[0] >= n)
		return 0;
	if(ar[len-1] < n)
		return len;
	if(len==1 && ar[0] < n)
		return 1;
	int mid = len/2;
	if(ar[mid-1] < n && n <= ar[mid] )
		return mid;
	if(ar[mid] < n)
		return 1+mid+ num_smaller_elements(ar+mid+1, len-mid-1, n);
	else
		return num_smaller_elements(ar,mid+1,n);
}

// returns the number of elements in ar[0..len] larger than n, given ar is sorted
int num_larger_elements(int* ar, int len, int n)
{
	if(ar[0] > n)
		return len;
	if(ar[len-1] <= n)
		return 0;
	if(len==1 && ar[0] > n)
		return 1;
	int mid = len/2;
	if(ar[mid-1] <= n && n < ar[mid] )
		return (len-mid);
	if(ar[mid] <= n)
		return num_larger_elements(ar+mid+1, len-mid-1, n);
	else
		return (len-mid)+num_larger_elements(ar,mid,n);
}

// i,j is the range we are querying.
// l,r is the range stored by index'th node in sorted order
// num of elements in range i,j that are smaller than 'num'
int query_for_smaller_in_segment(int i, int j, int l, int r, int index, int num)
{
	if(l>r)
		return 0;
	// if disjoint
	if(r<i || j<l)
		return 0;
	if(l>=i && r<=j)
		return num_smaller_elements(segment_tree[index].ar, segment_tree[index].len, num);
	else
	{
		int mid = (l+r)/2;
		return (query_for_smaller_in_segment(i,j,l,mid,2*index,num) + query_for_smaller_in_segment(i,j,mid+1,r,2*index+1,num));
	}
}

int query_for_larger_in_segment(int i, int j, int l, int r, int index, int num)
{
	if(l>r)
		return 0;
	// if disjoint
	if(r<i || j<l)
		return 0;
	if(l>=i && r<=j)
		return num_larger_elements(segment_tree[index].ar, segment_tree[index].len, num);
	else
	{
		int mid = (l+r)/2;
		return (query_for_larger_in_segment(i,j,l,mid,2*index,num) + query_for_larger_in_segment(i,j,mid+1,r,2*index+1,num));
	}
}

lli count_inversions(int ar[], int left, int right)
{
	// base case
	if(left==right)
		return 0;
	int mid = (left+right)/2;

	lli l = count_inversions(ar,left, mid);
	lli r = count_inversions(ar,mid+1, right);
	lli s = 0;
	int i=left, j=mid+1;
	int new_ar[right-left+1];
	int n_ind = 0;
	while(i<=mid || j<=right)
	{
		if(i>mid)
		{
			while(j<=right)
			{
				new_ar[n_ind] = ar[j];
				j++;
				n_ind++;
			}
			break;
		}

		if(j>right)
		{
			while(i<=mid)
			{
				new_ar[n_ind] = ar[i];
				i++;
				n_ind++;
			}
			break;
		}

		if(ar[i] <= ar[j])
		{
			new_ar[n_ind++] = ar[i++];
		}
		else
		{
			new_ar[n_ind++] = ar[j];
			s+=(mid-i+1);
			j++;
		}
	}

	f(i,right-left+1)
		ar[left+i] = new_ar[i];
	s+=(l+r);
	return s;
}

// on swapping i and j, what will be the change
int answer_query(int i, int j)
{
	int s=0;
	// printf("i = %d, j = %d\n",i,j );
	// printf("%d %d\n",ar[i],ar[j]);
	if(ar[i] > ar[j])
		s--;
	else if(ar[i] < ar[j])
		s++;
	// printf("init_s = %d\n",s);
	int old_i = query_for_smaller_in_segment(i+1,j-1,0,array_size-1,1,ar[i]);
	// printf("old_i = %d\n",old_i);
	int new_i = query_for_larger_in_segment(i+1,j-1,0,array_size-1,1,ar[i]);
	// printf("new_i = %d\n",new_i);
	int old_j = query_for_larger_in_segment(i+1,j-1,0,array_size-1,1,ar[j]);
	// printf("old_j = %d\n",old_j);
	int new_j = query_for_smaller_in_segment(i+1,j-1,0,array_size-1,1,ar[j]);
	// printf("new_j = %d\n",new_j);
	s = s-old_i+new_i-old_j+new_j;
	return s;
}

int main()
{
	int n,m,i,j,it,jt;
	g(n),g(m);
	array_size = n;
	f(i,n) g(ar[i]),br[i]=ar[i];
	create_segment_tree(ar,0,n-1,1);
	// f(i,n) printf("%d ", ar[i]); printf("\n");
	lli num_inv = count_inversions(br,0,n-1);
	printf("Yo\n");
	// f(i,n) printf("%d ", ar[i]); printf("\n");
	while(m--)
	{
		g(it),g(jt);
		it--,jt--;
		i = min(it,jt);
		j = max(it,jt);
		printf("%lld\n",num_inv + answer_query(i,j));
	}
	return 0;
}

