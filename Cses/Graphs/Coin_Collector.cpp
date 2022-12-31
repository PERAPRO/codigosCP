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

vector<vi> g;
vector<vi> rg;
vi visited;
vi component;
vi topo;

void dfs1(int u){
    visited[u] = 1;
    for(int v:g[u]){
        if(!visited[v])
            dfs1(v);
    }
    
    topo.pb(u);
}

vl costs;
ll c_cost = 0;

void dfs2(int u){
    visited[u] = 1;
    component.pb(u);
    c_cost += costs[u];
    for(int v:rg[u]){
        if(!visited[v])
            dfs2(v);
    }
}

int main(){
    fast_io;
    
    int n,m;
    cin>>n>>m;
    
    vi v(n);
    
    vl roots(n);
    vl root_nodes(n);
    costs.assign(n, 0);
    
    for(int i=0;i<n;i++){
        cin>>costs[i];
    }
    g.assign(n, vi());
    rg.assign(n, vi());
    
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        
        g[a].pb(b);
        rg[b].pb(a);
    }
    visited.assign(n,0);
    
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs1(i);
    }
    
    vl comp_costs(n);
    visited.assign(n,0);
    
    reverse(all(topo));
    
    for(int i:topo){
        if(!visited[i]){
            dfs2(i);
            
            int root = component.front();
            for(int u: component) roots[u] = root;
            
            root_nodes.pb(root);
            comp_costs[root] = c_cost;
            component.clear();
            c_cost = 0;
        }
    }
    
    vector<vi> adjscc(n);
    
    for(int i=0;i<n;i++){
        for(int v:g[i]){
            if(roots[i] != roots[v]){
                adjscc[roots[i]].pb(roots[v]);
            }
        }
    }
    ll ans = 0;
    vi distances(n, 1e8);
    
    vl memo(n);
    
    function<ll (int)> dfs3 = [&] (int u){
        if(memo[u]) return memo[u];
        ll cur_ans = 0;
        for(int v:adjscc[u]){
            ckmax(cur_ans, dfs3(v));
        }
        cur_ans += comp_costs[u];
        return memo[u] = cur_ans;
    };
    
    for(int rt:root_nodes){
        ckmax(ans, dfs3(rt));
    }
    
    cout<<ans<<el;
}