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
    vl mark;
    
    void init(int n){
        size=1;
        while(size < n) size <<= 1;
        values.assign(2 * size - 1,0);
        mark.resize(2 * size - 1);
        size--;
    };
    
    ll fn(ll a, ll b){
        return a + b;
    }
    
    void propagate(int node, int lx, int rx){
        //Si tengo algo en mark, es porque mis hijos no tienen esa info pero yo si
        if(lx == rx || mark[node] == 0) return;
        int m = (lx + rx) / 2;
        values[2 * node + 1] += mark[node] * (m - lx + 1);
        values[2 * node + 2] += mark[node] * (rx - (m + 1) + 1);
        mark[2 * node + 1] += mark[node];
        mark[2 * node + 2] += mark[node];
        mark[node] = 0;
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
            mark[node] += v;
            values[node] += v * (rx - lx + 1);
            return;
        }
        propagate(node, lx, rx);
        int m = (lx + rx) / 2;
        update(2 * node + 1, lx, m, l, r, v);
        update(2 * node + 2, m + 1, rx, l, r, v);
        values[node] = fn(values[2 * node + 1], values[2 * node + 2]);
    }
    void update(int l, int r, ll v){
        update(0, 0, size, l, r, v);
    }
    
    ll query(int node, int lx, int rx, int l, int r){
        propagate(node, lx, rx);
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
    int n,q,a,b,c,d;
    cin>>n>>q;
    vector<vi> grid(n + 1, vi(n + 1));
    string s;
    
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=n;j++){
            grid[i][j] = (s[j - 1] == '*');
        }
    }
    
    vector<vi> pref_sum(n + 1, vi(n + 1));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pref_sum[i][j] = grid[i][j] + pref_sum[i - 1][j] + pref_sum[i][j - 1] - pref_sum[i - 1][j - 1];
        }
    }
    
    while(q--){
        cin>>a>>b>>c>>d;
        cout<<pref_sum[c][d] + pref_sum[a - 1][b - 1] - pref_sum[c][b - 1] - pref_sum[a - 1][d]<<el;
    }
    
}

/*

*/