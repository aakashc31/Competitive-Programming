#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int ll;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

struct node
{
	int count;
	pii range;
};

bool compare(const node& a, const node& b)
{
	return a.range.first > b.range.first;
}
bool belongs(int n, pii& p)
{
	return (n>=p.first && n<=p.second);
}

int query(node* ar, int len, int num)
{
	if(len == 0) return 0;
	if(len == 1)
	{
		if(belongs(num, ar[0].range))
			return ar[0].count;
		else
			return 0;
	}
	int mid = len/2;
	if(belongs(num, ar[mid].range))
		return ar[mid].count;
	else if(num < ar[mid].range.first)
		return query(ar, mid, num);
	else
		return query(ar+mid+1, len-mid-1, num);
}

int main()
{
	int t,n,h;
	cin >> t;
	while(t--)
	{
		vector<node> gaps(0);
		cin >> n >> h;
		f(i,n)
		{
			int lower, upper;
			cin >> lower >> upper;
			node temp = {1, mp(lower,upper)};
			gaps.push_back(temp);
		}
		make_heap(gaps.begin(), gaps.end(), compare);
		vector<node> disjointGaps(0);
		disjointGaps.push_back(gaps.front());

		pop_heap(gaps.begin(), gaps.end(), compare);
		gaps.pop_back();

		while(!gaps.empty())
		{
			node curr = gaps.front();
			pop_heap(gaps.begin(), gaps.end(), compare);
			gaps.pop_back();

			node last = disjointGaps.back();
			// cout << "last = " << last.range.first << ", " << last.range.second << " count = "<< last.count << endl;
			// cout << "curr = " << curr.range.first << ", " << curr.range.second << " count = "<< curr.count << endl;
			if(last.range.first == curr.range.first && last.range.second == curr.range.second)
			{
				disjointGaps.back().count++;
			}

			else if(last.range.second < curr.range.first)
			{
				disjointGaps.push_back(curr);
			}
			else if(last.range.second < curr.range.second)
			{
				if(last.range.first != curr.range.first)
				{
					disjointGaps.back().range.second = curr.range.first - 1;
					pii midRange = mp(curr.range.first, last.range.second);
					node temp = {last.count + 1, midRange};
					disjointGaps.push_back(temp);

					curr.range.first = last.range.second + 1;
					gaps.push_back(curr);
					push_heap(gaps.begin(), gaps.end(), compare);
				}

				else
				{
					disjointGaps.back().count++;
					curr.range.first = last.range.second + 1;
					gaps.push_back(curr);
					push_heap(gaps.begin(), gaps.end(), compare);
				}
			}
			else if(last.range.second == curr.range.second)
			{
				disjointGaps.back().range.second = curr.range.first - 1;
				curr.count++;
				disjointGaps.push_back(curr);
			}
			else
			{
				if(last.range.first == curr.range.first)
				{
					disjointGaps.back().range.second = curr.range.second;
					disjointGaps.back().count++;

					pii otherHalf = mp(curr.range.second +1, last.range.second);
					node temp = {last.count, otherHalf};
					gaps.push_back(temp);
					push_heap(gaps.begin(), gaps.end(), compare);
				}
				else
				{
					disjointGaps.back().range.second = curr.range.first - 1;

					curr.count++;
					disjointGaps.push_back(curr);

					pii lastPart = mp(curr.range.second + 1, last.range.second);
					node temp = {last.count, lastPart};
					gaps.push_back(temp);
					push_heap(gaps.begin(), gaps.end(), compare);
				}
			}
		}

		node* ar = new node[disjointGaps.size()];
		int l = disjointGaps.size();
		for(int i=0; i<l; i++)
		{
			// cout << disjointGaps[i].range.first << ", " << disjointGaps[i].range.second << " count = " << disjointGaps[i].count << endl;
			ar[i] = disjointGaps[i];
		}
		//disjointGaps is sorted

		int base = ar[0].range.first;
		int ceiling = base + h - 1;
		ll ans = 0;
		for(int i=base; i<=ceiling; i++)
		{
			ll gapsInRow = query(ar, l, i);
			// cout << "gapsInRow = " << gapsInRow << endl;
			ans += (n-gapsInRow);
		}

		ceiling++; base++;
		// cout << "ans = " << ans << ", base = " << base-1 << endl;
		while(ceiling < n)
		{
			ll sub = n-query(ar,l,base-1);
			ll add = n-query(ar,l,ceiling);
			ll temp = ans + add - sub;
			if(temp < ans) ans = temp;
			ceiling++; base++;
			// cout << "ans = " << ans << ", base = " << base-1 << endl;
		}

		cout << ans << endl;
	}
	return 0;
}
