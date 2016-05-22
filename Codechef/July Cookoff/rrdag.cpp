#include <iostream>
#include <list>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;


#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)
typedef pair<int,int> tuple;

int ar[1500];
tuple new_edges[2250000];
int index;

bool lcompare(const tuple& fir, const tuple& sec)
{
	return fir.first < sec.first;
}


bool rcompare(const tuple& fir, const tuple& sec)
{
	return fir.second < sec.second;
}


class Graph
{
    int V;    
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack which stores result
    Stack.push(v);
}
 
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    index = 0;
    while (Stack.empty() == false)
    {
        // cout << Stack.top() << " ";
    	ar[index++] = Stack.top();
        Stack.pop();
    }
}




char ch[1500][1500];
int main()
{
	int n; //number of nodes
	getNum(n);
	Graph g(n);
	
	int m=0; //number of edges
	f(i,n)
	{
		scanf("%s",ch[i]);
		f(j,n)
		{
			if(ch[i][j]=='1')
			{
				g.addEdge(i,j);
				m++;
			}
		}
	}
	// graph constructed
	g.topologicalSort();
	int numNew = ((n*(n-1))/2) - m;
	printf("%d\n",numNew); //
	int l=0;
	f(i,n)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ch[i][j]=='0')
				new_edges[l++] = pair<int,int>(i,j);
		}
	}
	sort(new_edges, new_edges+l, rcompare);
	stable_sort(new_edges, new_edges+l, lcompare);
	f(i,l)
	{
		printf("%d %d\n", new_edges[i].first+1, new_edges[i].second+1);
	}
	return 0;
}