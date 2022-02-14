/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
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
    int size;
    vector<ll> values;
    
    void init(int n){
        size=1;
        while(size<n) size*=2;
        values.resize(2*size-1);
        size--;
    }
    
    void build(vl &a, int node, int lx, int rx){
        if(lx==rx){
            if(lx<a.size()){
                values[node]=a[lx];
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*node+1,lx,m);
        build(a,2*node+2,m+1,rx);
        values[node]=values[2*node+1]+values[2*node+2];
    }
    
    void build(vl &a){
        build(a,0,0,size);
    }
    
    void set(int i, ll v, int node, int lx, int rx){
        if(lx==rx){
            if(i>-1 && i<=size) values[node]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<=m){
            set(i,v,2*node+1,lx,m);
        }else{
            set(i,v,2*node+2,m+1,rx);
        }
        values[node]=values[2*node+1]+values[2*node+2];
    }
    
    void set(int i, int  v){
        set(i,v,0,0,size);
    }
    
    ll sum(int l, int r, int node, int lx, int rx){
        if(lx>=l && rx<=r) return values[node];
        if(lx>r || rx<l) return 0;
        int m=(lx+rx)/2;
        ll s1=sum(l,r,2*node+1,lx,m);
        ll s2=sum(l,r,2*node+2,m+1,rx);
        return s1+s2;
    }
    
    ll sum(int l, int r){
        return sum(l,r,0,0,size);
    }
};

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q,a,b;
    cin>>n>>q;
    vl v(n);
    for(ll &e:v) cin>>e;
    segtree st;
    st.init(n);
    st.build(v);
    
    string type;
    for(int Q=0;Q<q;Q++){
        cin>>type;
        if(type == "q"){
            cin>>a>>b;
            a--,b--;
            cout<<st.sum(a,b)<<el;
        }else{
            cin>>a>>b;
            a--;
            ll cur=st.sum(a,a);
            st.set(a,cur + b);
        }
    }
}

/*

*/