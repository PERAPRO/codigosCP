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

const int oo = 1e9+3;

bool belong(int &i, int l, int r){
    return (i >= l && i <= r);
}

struct segtree{
    int l, r;
    int value = 0;
    
    segtree *left = nullptr, *right = nullptr;
    
    segtree(int l, int r) : l(l) , r(r){} 
    
    void update(int &idx, int val){
        //if(!belong(idx, l, r)) return;
        if(l == r){
            value += val;
            return;
        }
        int m = (l + r) / 2;
        
        if(!left && belong(idx , l, m)) left = new segtree(l, m);
        if(!right && belong(idx, m + 1, r)) right = new segtree(m + 1, r);
        
        if(left && belong(idx , l, m)) left->update(idx, val);
        if(right && belong(idx, m + 1, r)) right->update(idx, val);
        
        int izq = (left ? left->value : 0);
        int der = (right ? right->value : 0);
        
        value =  izq + der;
    }
    
    int query(int &a, int &b){
        if(a <= l && b >= r) return value;
        if(r < a || l > b) return 0;
        
        int izq = (left ? left->query(a, b) : 0);
        int der = (right ? right->query(a, b) : 0);
        return izq + der;
    }
    
};

int main(){
    fast_io;
    /*
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n, q, a, b, idx, val;
    cin>>n>>q;
    
    vi v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    segtree st(1,oo);
    
    for(int salary:v){
        st.update(salary,1);
    }
    
    char type;
    
    while(q--){
        cin>>type;
        if(type == '!'){
            cin>>idx>>val;
            idx--;
            st.update(v[idx], -1);
            v[idx] = val;
            st.update(val, 1);
        }else{
            cin>>a>>b;
            //a--,b--;
            cout<<st.query(a,b)<<el;
        }
    }
    
}

/*

*/