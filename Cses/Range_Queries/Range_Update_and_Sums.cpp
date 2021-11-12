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
 
struct segtree{
    ll l = 0,r = 0;
    segtree *left = nullptr, *right = nullptr;
    
    ll value = 0, value2 = 0;
    
    ll sums = 0;
    
    ll mark = 0;
    
    bool set_zero = 0;
    
    segtree(ll l, ll r, vl &v): l(l), r(r){
        if(l == r){
            value = v[l];
            return;
        }
        ll m = (l + r) / 2;
        
        left = new segtree(l, m, v);
        right = new segtree(m + 1, r, v);
        
        value = left->value + right->value;
    }
    
    void push1(){
        if(!mark || l == r) return;
        left->mark = mark, right->mark = mark;
        
        left->value = mark * (left->r - left->l + 1);
        right->value = mark * (right->r - right->l + 1);
        
        mark = 0;
    }
    
    void push2(){
        if(!sums || l == r) return;
        left->sums += sums, right->sums += sums;
        
        left->value2 += sums * (left->r - left->l + 1);
        right->value2 += sums * (right->r - right->l + 1);
        
        sums = 0;
    }
    
    void push3(){
        if(!set_zero || l == r) return;
        left->sums = 0, right->sums += 0;
        
        left->value2 = 0;
        right->value2 = 0;
        
        left->set_zero = 1;
        right->set_zero = 1;
        
        set_zero = 0;
    }
    
    void update1(ll lx, ll rx, ll k){ //Query change the value
        push1();
        if(l > rx || r < lx) return;
        if(l >= lx && r <= rx){
            value = k * (r - l + 1);
            mark = k;
            return;
        }
        left->update1(lx, rx, k);
        right->update1(lx, rx, k);
        
        value = left->value + right->value;
    }
    
    void update2(ll lx, ll rx, ll k){
        push3();
        push2();
        if(l > rx || r < lx) return;
        if(l >= lx && r <= rx){
            value2 += k * (r - l + 1);
            sums += k;
            return;
        }
        left->update2(lx, rx, k);
        right->update2(lx, rx, k);
        
        value2 = left->value2 + right->value2;
    }
    
    void update0(ll lx, ll rx){
        push3();
        push2();
        if(l > rx || r < lx) return;
        if(l >= lx && r <= rx){
            value2 = 0;
            sums = 0;
            set_zero = 1;
            return;
        }
        left->update0(lx, rx);
        right->update0(lx, rx);
        
        value2 = left->value2 + right->value2;
    }
    
    ll query1(int lx, int rx){
        push1();
        if(l > rx || r < lx) return 0LL;
        if(l >= lx && r <= rx){
            return value;
        }
        return left->query1(lx, rx) + right->query1(lx, rx);
    }
    
    ll query2(int lx, int rx){
        push3();
        push2();
        if(l > rx || r < lx) return 0LL;
        if(l >= lx && r <= rx){
            return value2;
        }
        return left->query2(lx, rx) + right->query2(lx, rx);
    }
};
 
int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q;
    cin>>n>>q;
    
    vl v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    segtree st(0 , n - 1, v);
    
    int type,lx,rx,k;
    while(q--){
        cin>>type>>lx>>rx;
        lx--, rx--;
        if(type == 1){
            cin>>k;
            st.update2(lx, rx, k);
        }else if(type == 2){
            cin>>k;
            st.update1(lx, rx, k);
            st.update0(lx, rx);
        }else{
            //cout<<st.query1(lx, rx)<<esp<<st.query2(lx, rx)<<el;
            cout<<st.query1(lx, rx) + st.query2(lx, rx)<<el;
        }
    }
}
 
/*
 
*/