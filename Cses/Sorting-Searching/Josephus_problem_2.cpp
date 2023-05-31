/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vi=vector<int>;
using vl=vector<ll>;
using pii=pair<int,int>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    indexed_set s;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    int init = 0;
    while(s.size()){
        init = (init + (k)) % s.size();
        int value =  *s.find_by_order(init);
        s.erase(value);
        // for(int element: s) cout<<element<<esp;
        // cout<<el;
        // cout<<s.size()<<el;
        cout<<value<<esp;
    }
}

/*
1 2 3 4 5 6 7
*/