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

struct bit2d{
    
    int n;
    vector<vi> bit;
    
    void init(int size){
        n = size + 1;
        bit.assign(n ,vi(n, 0));
    }
    
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void update(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < n; j = j | (j + 1))
                bit[i][j] += delta;
    }
    
};

int main(){
    fast_io;
    /*
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n, q, type, a, b, c, d, idx;
    cin>>n>>q;
    string s;
    
    bit2d bit;
    bit.init(n);
    
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j - 1] == '*'){
                bit.update(i , j , 1);
            }
        }
    }
    
    //cout<<bit.sum(n, n)<<el;
    
    while(q--){
        cin>>type;
        if(type == 1){
            cin>>c>>d;
            a = c - 1, b = d - 1;
            int state =  bit.sum(c, d) + bit.sum(a, b) - bit.sum(c , b) - bit.sum(a , d);
            if(state)
                bit.update(c , d, -1);
            else
                bit.update(c , d, 1);
        }else{
            cin>>a>>b>>c>>d;
            cout<<bit.sum(c, d) + bit.sum(a - 1, b - 1) - bit.sum(c , b - 1) - bit.sum(a - 1 , d)<<el;
        }
    }
}

/*

*/