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

struct item{
    ll pref, suf, sum, seg;
    item(){}
    item(ll val): pref(val), suf(val), sum(val), seg(val){}
};

struct segtree{
    int l, r;
    item value;
    segtree *left, *right;
    
    void merge(){
        value.pref = max(left->value.pref, left->value.sum + right->value.pref);
        value.suf = max(right->value.suf, right->value.sum + left->value.suf);
        value.seg = max({left->value.seg, right->value.seg, left->value.suf + right->value.pref});
        value.sum = left->value.sum + right->value.sum;
    }
    
    segtree(int l, int r, vl &v) : l(l), r(r){
        if(l == r){
            value = item(v[l]);
            return;
        }
        int m = (l + r) / 2;
        left = new segtree(l, m, v);
        right = new segtree(m + 1, r, v);
        merge();
    }
    
    void update(int &idx, int &val){
        if(idx > r || idx < l) return;
        if(l == r){
            value = item(val);
            return;
        }
        
        left->update(idx, val);
        right->update(idx, val);
        merge();
    }
};

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n, q, idx, val;
    cin>>n>>q;
    vl v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    segtree st(0, n - 1, v);
    
    while(q--){
        cin>>idx>>val;
        idx--;
        st.update(idx, val);
        cout<<max(0LL, st.value.seg)<<el;
    }
}

/*

*/