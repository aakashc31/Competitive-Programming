#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair< int , int > pii;

int main() {
    int t;
    cin>>t;
    char c;
    int n;
    int insert_counter = 0;
    tree < pii , null_type , less<pii> , rb_tree_tag , tree_order_statistics_node_update > T;

    for (int i = 0;i<t;i++) {
        cin>>c>>n;
        if (c == 'r') {           
            auto it = T.find_by_order( T.order_of_key( {n,-1} ) );
            if( it == T.end() || it->first != n ) {
                cout<<"Wrong!"<<endl;
                continue;
            }
            else {
                T.erase( T.find_by_order( T.order_of_key( {n,-1} ) ) );
            }
        }
        else if (c == 'a') {
            T.insert(make_pair(n,insert_counter++));
        }
        if (T.size()==0) {
            cout<<"Wrong!"<<endl;
            continue;
        }
        else if (T.size()%2 == 1) {
            cout<<T.find_by_order(T.size()/2)->first<<endl;
        }
        else {
            long long int t1 = T.find_by_order(T.size()/2)->first;
            long long int t2 = T.find_by_order(T.size()/2 -1)->first;
            long long int temp = t1 + t2;
            if (temp == -1) cout<<"-";
            cout<<temp/2;    
            if (temp<0)temp*=-1;
            if (temp%2==1) {
                cout<<".5";
            }
            cout<<endl;
        }

    }
    return 0;
}