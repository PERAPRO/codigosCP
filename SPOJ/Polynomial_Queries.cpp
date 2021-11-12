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
string yes="Yes";
string no="No";

const pii nop = {-1, -1};

ll triangular(pii p){
    if(p.ff < 0 && p.ss < 0) return 0;
    p.ff--;
    ll f = p.ff * 1LL * (p.ff + 1) / 2;
    ll s = p.ss * 1LL * (p.ss + 1) / 2;
    return s - f;
}

struct segtree{
    int l = 0, r = 0;
    ll value = 0;
    segtree *left = nullptr, *right = nullptr;
    pii range = nop;
    
    segtree(int l, int r, vl &v): l(l), r(r){
        if(l == r){
            value = v[l];
            return;
        }
        int m = (l + r) / 2;
        left = new segtree(l , m, v);
        right = new segtree(m + 1, r, v);
        value = left->value + right->value;
    }
    
    void push(){
        if(range == nop) return;
        //Aplico las operaciones de mis hijos y ahi si les dejo los pendientes ?
        int m = (l + r) / 2;
        
        left->value += triangular(make_pair(range.ff, range.ff + m));
        right->value += triangular(make_pair(range.ff + m + 1, range.ss));
        
        left->range = {range.ff, range.ff + m};
        right->range = {range.ff + m + 1, range.ss};
        
        range = nop;
    }
    
    void update(int lx, int rx, pii values){
        if(r < lx || l > rx) return;
        if(l >= lx && r <= rx){
            range = values;
            value += triangular(values);
            return;
        }
        push();
        int m = (l + r) / 2;
        if(m >= lx && rx > m){ // Me divido en los dos hijos
            int left_c = m - lx + 1;
            left->update(lx, rx, make_pair(values.ff, values.ff + left_c));
            right->update(lx, rx, make_pair(values.ff + left_c + 1, values.ss));
        }else if(m >= lx){
            left->update(lx, rx, values);
        }else{
            right->update(lx, rx, values);
        }
        value = left->value + right->value;
    }
    
    ll query(int lx, int rx){
        if(r < lx || l > rx) return 0;
        if(l >= lx && r <= rx){
            return value;
        }
        push();
        return left->query(lx, rx) + right->query(lx, rx);
    }
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q,type,a,b;
    cin>>n>>q;
    vl v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    segtree st(0, n - 1, v);
    while(q--){
        cin>>type>>a>>b;
        a--,b--;
        if(type == 1){
            st.update(a, b, make_pair(1, 1 + (b - a)));
        }else{
            cout<<st.query(a, b)<<el;
        }
    }
}

/*

*/