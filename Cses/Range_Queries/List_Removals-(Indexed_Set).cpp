/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using pii=pair<int,int>;
typedef tree<pii, null_type,less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
using vi=vector<int>;
using vl=vector<ll>;
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
    int n, idx;
    cin>>n;
    vi v(n);
    
    indexed_set s;
    
    for(int i=0;i<n;i++){
        cin>>v[i];
        s.insert({i,v[i]});
    }
    
    for(int i=0;i<n;i++){
        cin>>idx;
        idx--;
        pii ans = *s.find_by_order(idx);
        s.erase(ans);
        cout<<ans.ss<<esp;
    }
}

/*

*/