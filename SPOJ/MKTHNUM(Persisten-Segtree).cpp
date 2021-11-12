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
    int l, r;
    int value = 0;
    segtree *left, *right;
    
    segtree(int value) : left(nullptr), right(nullptr), value(value) {}
    
    segtree(segtree *left, segtree *right): left(left), right(right) {
        if(left) value += left ->value;
        if(right) value += right ->value;
    }
    
};

segtree* build(int lx, int rx){
    if(lx == rx)
        return new segtree(0);
    int m = (lx + rx) / 2;
    return new segtree(build(lx, m), build(m + 1, rx));
}

segtree* update(segtree *v, int lx, int rx, int idx){
    if(lx == rx){
        return new segtree(v->value + 1);
    }
    int m = (lx + rx) / 2;
    
    if(idx <= m)
        return new segtree(update(v->left, lx, m, idx), v->right);
    return new segtree(v->left, update(v->right, m + 1, rx, idx));
}

int find_kth(segtree *vl, segtree *vr,int lx, int rx, int k){
    if(lx == rx)
        return lx;
    int m = (lx + rx) / 2;
    int left_count = vr->left->value - vl->left->value;
    if(k <= left_count)
        return find_kth(vl->left, vr->left, lx, m, k);
    return find_kth(vl->right, vr->right, m + 1, rx, k - left_count);
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q;
    cin>>n>>q;
    
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    vi srt = v;
    sort(all(srt));
    
    srt.erase(unique(all(srt)), srt.end());
    
    vector<segtree*> roots;
    roots.pb(build(0, n - 1));
    
    for(int i=0;i<n;i++){
        roots.pb(update(roots.back(), 0, n - 1, lower_bound(all(srt), v[i]) - srt.begin()));
    }
    
    int i,j,k;
    //cout<<srt;
    while(q--){
        cin>>i>>j>>k;
        //cout<<"Normal value = "<<find_kth(roots[i - 1], roots[j], 0, n - 1, k)<<el;
        cout<<srt[find_kth(roots[i - 1], roots[j], 0, n - 1, k)]<<el;
    }
    
}

/*

*/