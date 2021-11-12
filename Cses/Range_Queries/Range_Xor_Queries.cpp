/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
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

const ll oo = 1e15;

struct segtree{
    int size;
    vl values;
    
    void init(int n){
        size=1;
        while(size < n) size <<= 1;
        values.assign(2 * size - 1,0);
        size--;
    };
    
    ll fn(ll a, ll b){
        return a ^ b;
    }
    
    void build(int node, int lx, int rx, vl &v){
        if(lx == rx){
            if(lx < v.size())
                values[node] = v[lx];
            return;
        }
        int m=(lx + rx) / 2;
        build(2 * node + 1, lx, m, v);
        build(2 * node + 2, m + 1, rx, v);
        values[node] = fn(values[2 * node + 1], values[2 * node + 2]);
    }
    
    void build(vl &v){
        build(0, 0, size, v);
    }
    
    void update(int node, int lx, int rx, int l, int r, ll v){
        if(rx < l || lx > r) return;
        if(lx >= l && rx <= r){
            values[node] = v;
            return;
        }
        int m = (lx + rx) / 2;
        update(2 * node + 1, lx, m, l, r, v);
        update(2 * node + 2, m + 1, rx, l, r, v);
        values[node] = fn(values[2 * node + 1], values[2 * node + 2]);
    }
    void update(int l, int r, ll v){
        update(0, 0, size, l, r, v);
    }
    
    ll query(int node, int lx, int rx, int l, int r){
        if(rx < l || lx > r) return 0;
        if(lx >= l && rx <= r) return values[node];
        int m = (lx + rx) / 2;
        return fn(query(2 * node + 1, lx, m, l, r), query(2 * node + 2, m + 1, rx, l, r)); 
    }
    
    ll query(int l, int r){
        return query(0, 0, size, l, r);
    }
    
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n, q, l, r, type, idx, k;
    cin>>n>>q;
    
    vl v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    segtree st;
    st.init(n);
    st.build(v);
    
    while(q--){
        {
            cin>>l>>r;
            l--,r--;
            cout<<st.query(l,r)<<el;
        }
    }
}

/*

*/