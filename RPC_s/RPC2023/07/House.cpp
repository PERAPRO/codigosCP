/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

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

struct segtree{
    ll value = 0;
    int l,r;
    segtree *left, *right;
    
    segtree (int l, int r, vl &v): l(l), r(r){
        if(l == r){
            value = v[l];
            return;
        }
        int m = (l + r) / 2;
        left = new segtree(l, m, v);
        right = new segtree(m + 1, r, v);
        value = left->value + right->value;
        // unos = left->unos + right->unos;
    }
    
    void update(int lx, int rx, ll v){
        if(lx > r || rx < l) return;
        
        if(l >= lx && r <= rx){
            value += v;
            return;
        }
        left->update(lx, rx, v);
        right->update(lx, rx, v);
        value = left->value + right->value;
    }
    
    ll query(int lx, int rx){
        if(lx > r || rx < l) return 0;
    
        if(l >= lx && r <= rx){ 
            return value;
        }
        return left->query(lx, rx) + right->query(lx, rx);
    }
    
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n;
    cin>>n;
    vl v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    
    segtree st(0, n - 1, v);
    
    int t;
    cin>>t;
    while(t--){
        char type;
        cin>>type;
        if(type == 'U'){
            int idx,value;
            cin>>idx>>value;
            idx--;
            st.update(idx, idx, value);
        }else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<st.query(l,r)<<el;
        }
    }
}

/*

*/