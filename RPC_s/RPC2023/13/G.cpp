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

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const pair<T,T> &p){
    os<<'('<<p.ff<<','<<p.ss<<')';
    os<<' ';
    return os;
}

string yes="YES";
string no="NO";

struct segtree{
    int l, r;
    segtree *left = nullptr, *right = nullptr;
    ll value = 0, lazy = 0;
    segtree(int l, int r) : l(l), r(r){
        if(l == r){
            return;
        }
        int m = (l + r) / 2;
        left = new segtree(l, m);
        right = new segtree(m + 1, r);
        
        value = left->value + right->value;
    }
    void propagate(){
        if(!lazy || l == r) return;
        left->value += lazy * (left->r - left->l + 1);
        right->value += lazy * (right->r - right->l + 1);
        left->lazy += lazy;
        right->lazy += lazy;
        
        lazy = 0;
    }
    
    void update(int lx, int rx, ll v){
        propagate();
        if(l > rx || r < lx) return;
        if(l >= lx && r <= rx){
            value = v * (r - l + 1);
            lazy = v;
            return;
        }
        left->update(lx, rx, v);
        right->update(lx, rx, v);
        
        value = left->value + right->value;
    }
    
    ll query(int lx, int rx){
        propagate();
        if(l > rx || r < lx) return 0;
        if(l >= lx && r <= rx) return value;
        
        return left->query(lx, rx) + right->query(lx, rx);
    }
};

const int N = 1e5+5, LOG2 = 25;

vector<vi> jump(N, vi(LOG2));
vi depth(N);


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,q;
    cin>>n>>q;
    vector<vi> g(n);
    
    segtree st(0, 2*n);
    
    vector<pii> vals(n);
    
    for(int i = 0;i<n;i++){
        cin>>vals[i].ff;
        vals[i].ss = i;
    }
    
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].pb(b), g[b].pb(a);
    }
    
    int timer = 0;
    vi in(n), out(n), et(2 * n);
    
    function<void(int, int)> dfs = [&] (int u,int p){
        in[u] = timer;
        et[timer++] = u;
        jump[u][0] = p;
        
        for(int j = 0;j + 1< LOG2;j++){
            jump[u][j + 1] = jump[jump[u][j]][j];
        }
        
        for(int v:g[u]){
            if(v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
        out[u] = timer;
        et[timer++] = u; 
    };
    
    function<int(int,int)> get_lca = [&] (int u, int v){
        // cout<<"lca : "<<u<<esp<<v<<el;
        if(depth[u] < depth[v]) swap(u, v);
        
        for(int j = LOG2 - 1; j>=0; j--){
            if(depth[jump[u][j]] >= depth[v]){
                u = jump[u][j];
            }
        }
        
        if(u == v) return u;
        
        for(int j = LOG2 - 1; j>=0; j--){
            if(jump[u][j] != jump[v][j]){
                u = jump[u][j];
                v = jump[v][j];
            }
        }
        
        return jump[u][0];
    };

    
    dfs(0,0);
    // cout<<et;
    
    // for(int i = 0;i<n;i++){
    //     st.update(in[i], in[i], vals[i]);
    //     st.update(out[i], out[i], -vals[i]);
    // }
    vector<pair<pii,pii>> queries(q);
    for(int query = 0;query < q;query++){
        int a,b,x;
        cin>>a>>b>>x;
        a--,b--;
        queries[query] = {{x,query},{a,b}};
    }
    sort(all(queries));
    sort(vals.rbegin(), vals.rend());
    
    vi ans(q);
    vi lcas(n);
    for(int query = 0;query<q;query++){
        // cout<<queries[query]<<el;
        while(vals.size() && vals.back().ff <= queries[query].ff.ff){
            // cout<<vals.back()<<el;
            int val = vals.back().ff;
            int i = vals.back().ss;
            
            st.update(in[i], in[i], 1);
            st.update(out[i], out[i], -1);
            lcas[i] = 1;
            vals.pop_back();
        }
        
        int a = queries[query].ss.ff;
        int b = queries[query].ss.ss;
        int lca = get_lca(a, b);
        // cout<<lca<<el;
        ans[queries[query].ff.ss] = st.query(0, in[a]) + st.query(0, in[b]) - (2 * st.query(0, in[lca])) + lcas[lca];
    }
    
    for(int x:ans){
        cout<<x<<el;
    }
}

/*

*/