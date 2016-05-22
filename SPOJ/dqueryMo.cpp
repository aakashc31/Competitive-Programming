#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define getcx getchar//_unlocked
inline ll inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}
#define BLOCK 555
const int maxa = 1e6+10; const int N = 30010; const int maxq = 200010;
int ar[N]; int cnt[maxa]; int answers[maxq];
int answer=0; 

struct node{
	int L, R, i;
}q[maxq];

bool cmp(node x, node y){
	if(x.L/BLOCK != y.L/BLOCK)
		return x.L/BLOCK < y.L/BLOCK;
	return x.R < y.R;
}

void add(int position){
	cnt[ar[position]]++;
	if(cnt[ar[position]] == 1)
		answer++;
}

void remove(int position){
	cnt[ar[position]]--;
	if(cnt[ar[position]] == 0)
		answer--;
}

int main(){
	int n = inp(),d,x,y;
	for(int i=0; i<n; i++)
		ar[i] = inp();
	d = inp(); 
	for(int i=0; i<d; i++){
		q[i].L = inp()-1; q[i].R = inp()-1;
		q[i].i = i;
	}
	sort(q, q+d, cmp);
	int currentL = 0, currentR = 0;
	for(int i=0; i<d; i++){
		int L = q[i].L, R = q[i].R;
		while(currentL < L){
			remove(currentL);
			currentL++;
		}
		while(currentL > L){
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R){
			add(currentR);
			currentR++;
		}
		while(currentR > R+1){
			remove(currentR-1);
			currentR--;
		}
		answers[q[i].i] = answer;
	}
	for(int i=0; i<d; i++)
		printf("%d\n", answers[i]);
	return 0;
}