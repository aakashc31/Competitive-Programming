#include <bits/stdc++.h>

using namespace std;

#define getcx getchar//_unlocked
#define f(i,n) for(int i=0; i<n; i++)

inline void get( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int, int> pii;

const int inf = 1000000;

vvi out_graph(100000,vi(1,0)); //for every vertex a, stores those b, s.t. a->b. and out_graph[a][0] = no. of outgoing edges

vvi in_graph(100000,vi(1,0)); // for every vertex a, stores those b, s.t. a<-b. and out_graph[a][0] = no. of incoming edges

pii ar[100000]; //stores tuples (a,b), where a is the index of vertex in graph, and b is the minimum number of reversals reqd. to reach from 0 to a
int size;

int index_in_heap[100000]; //stores the index of vertices in the heap, for log(n) update.

bitset<100000> is_visited; //visits a vertex if it's min_rev is calculated.

int rev_min[100000];

void swap(pii& a, pii& b)
{
	pii temp = pii(a.first,a.second);
	a = pii(b.first,b.second);
	b = pii(temp.first, temp.second);
}
bool compare(const pii& a, const pii& b)
{
	return (a.second > b.second);
}

void upheap(int i)
{
	if(i==0)
		return;
	int parent = (i-1)/2;
	if(ar[i].second >= ar[parent].second)
		return;
	index_in_heap[ar[i].first] = parent;
	index_in_heap[ar[parent].first] = i;
	swap(ar[i],ar[parent]);
	upheap(parent);
}


void downheap(int i)
{
	if(2*i+1 >= size) //if is external
		return;
	if((2*i+2)<size) //if non leaf with two children.
	{
		int toSwap = (ar[2*i+1].second < ar[2*i+2].second) ? (2*i+1):(2*i+2);
		if(ar[i].second <= ar[toSwap].second)
			return;
		index_in_heap[ar[i].first] = toSwap;
		index_in_heap[ar[toSwap].first] = i;
		swap(ar[i],ar[toSwap]);
		downheap(toSwap);
	}
	else if(2*i+2 == size) //if non leaf with one child
	{
		int toSwap = 2*i+1;
		if(ar[i].second <= ar[toSwap].second)
			return;
		index_in_heap[ar[i].first] = toSwap;
		index_in_heap[ar[toSwap].first] = i;
		swap(ar[i],ar[toSwap]);
		downheap(toSwap);
	}
	
}

void update_heap(int i, int val)
{
	ar[i].second = val; //this will always decrease. So upheap
	upheap(i);
}

pii remove_min() 
{
	pii ret = pii(ar[0].first,ar[0].second);
	swap(ar[0],ar[size-1]);
	size--;
	downheap(0);
	return ret;
}

int main()
{
	int n,m;
	get(n),get(m);
	f(i,m)
	{
		int a,b;
		get(a), get(b);
		if(a==b)
			continue;
		out_graph[a-1].push_back(b-1);
		out_graph[a-1][0]++;
		
		in_graph[b-1].push_back(a-1);
		in_graph[b-1][0]++;
	}

	if(n==1)
	{
		printf("0");
		return 0;
	}

	is_visited.set();
	is_visited.flip();

	f(i,n) ar[i] = (pii(i,inf)), rev_min[i]=inf;

	ar[0] = pii(0,0);
	rev_min[0] = 0;
	size = n; 
	
	f(i,size)
		index_in_heap[ar[i].first] = i;

	while(size>0)
	{
		
		pii temp = remove_min(); 

		int i = temp.first;
		int k = temp.second;
		
		is_visited[i]=1;
		rev_min[i] = k;

		if(n-1==i)
			break;

		for(int j=1;j<=out_graph[i][0];j++)
		{
			int neigh = out_graph[i][j];
			if(!is_visited[neigh])
			{
				int rev_min_of_neigh = rev_min[neigh];
				if(rev_min_of_neigh > k)
				{
					rev_min[neigh] = k;
					update_heap(index_in_heap[neigh],k);
				}
			}
		}
		for(int j=1;j<=in_graph[i][0];j++)
		{
			int neigh = in_graph[i][j];
			if(!is_visited[neigh])
			{
				int rev_min_of_neigh = rev_min[neigh];
				if(rev_min_of_neigh > k+1)
				{
					rev_min[neigh] = k+1;
					update_heap(index_in_heap[neigh],k+1);
				}
			}
		}
	}
	
	// 
	if(rev_min[n-1]!=inf)
		printf("%d",rev_min[n-1]);
	else 
		printf("-1");
	return 0;	
}