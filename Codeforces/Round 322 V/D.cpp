#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;


char ch[1000][1000];

int main(){
	int flag = 0;
	int x[3], y[3], area = 0;
	for(int i=0; i<3; i++){
		cin >> x[i] >> y[i];
		area += x[i] * y[i];
	}
	int x1,x2,x3,y1,y2,y3;

	int edge = sqrt(area);
	if(edge * edge != area){
		cout << "-1" << endl;
		return 0;
	}

	for(int i=0; i<2; i++){
		x1 = x[0], y1 = y[0];
		if(i&1) swap(x1,y1);

		for(int j=0; j<2; j++){
			x2 = x[1], y2 = y[1];
			if(j&1) swap(x2,y2);

			for(int k=0; k<2; k++){
				x3 = x[2], y3 = y[2];
				if(k&1) swap(x3,y3);

				if(x1 == edge){
					if(x2 + x3 == edge && y2 == (edge - y1) && y3 == y2){
						flag = 1;
						for(int p=0; p<y1; p++){
							for(int q=0; q<x1; q++){
								ch[p][q] = 'A';
							}
						}
						for(int p=y1; p<edge; p++){
							for(int q=0; q<edge; q++){
								if(q<x2)
									ch[p][q] = 'B';
								else
									ch[p][q] = 'C';
							}
						}
						goto outer;
					}
				}
				else if(x2 == edge){
					if(x1 + x3 == edge  && y1 == (edge - y2) && y3 == y1){
						flag = 2;
						for(int p=0; p<y2; p++){
							for(int q=0; q<x2; q++){
								ch[p][q] = 'B';
							}
						}
						for(int p=y2; p<edge; p++){
							for(int q=0; q<edge; q++){
								if(q<x1)
									ch[p][q] = 'A';
								else
									ch[p][q] = 'C';
							}
						}
						goto outer;
					}
				}
				else if(x3 == edge){
					if(x1+x2==edge && y1 == (edge - y3) && y2 == y1){
						for(int p=0; p<y3; p++){
							for(int q=0; q<x3; q++){
								ch[p][q] = 'C';
							}
						}
						for(int p=y3; p<edge; p++){
							for(int q=0; q<edge; q++){
								if(q<x2)
									ch[p][q] = 'B';
								else
									ch[p][q] = 'A';
							}
						}
						flag = 3;
						goto outer;
					}						
				}


				if(x1==x2 && x2 == x3 && x1 == edge && (y1+y2+y3) == edge){
					for(int p=0; p<edge; p++){
						for(int q=0; q<edge; q++){
							if(p<y1)
								ch[p][q] = 'A';
							else if(p < (y1+y2))
								ch[p][q] = 'B';
							else
								ch[p][q] = 'C';
						}
					}

					flag = 7;
					goto outer;
				}					
			}
		}
	}

	outer:
	if(flag == 0){
		cout << "-1" << endl;
		return 0;
	}
	cout << edge << endl;
	for(int i=0;i<edge;i++){
		for(int j=0; j<edge;j++){
			cout << ch[i][j];
		}
		cout << endl;
	}
	return 0;
}