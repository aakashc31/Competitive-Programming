#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define f(i,n) for(int i=0;i<n;i++)


struct node 
{
	int val;
	node* left;
	node* right;
	bool isExternal = true;
};

class BST
{

public:
	node* root;
	BST(int a)
	{
		root = new node;
		root -> val = a;
		root -> isExternal = false;
	}

	//returns the node which will either be the searched node, or an external node, where insertion can be done
	bool search(int n)
	{
		node* temp = root;
		while(!(temp -> isExternal))
		{
			if(temp->val == n)
				break;
			else if(temp->val < n)
				temp = temp -> right;
			else 
				temp = temp -> left;
		}
		return temp;
	}

	void insert(int n)
	{
		
	}
};