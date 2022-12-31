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

const int N = 2e5+5;
const int Log2 = 25;

vi depth(N);
vector<vi> jump(N, vi(Log2));
vi values(N);
vi ans(N);
vector<vi> g(N);

void dfs(int u, int p){
    
    jump[u][0] = p;
    
    for(int j = 0;j + 1< Log2;j++){
        jump[u][j + 1] = jump[ jump[u][j] ][j];
    }
    
    for(int v:g[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int get_lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    
    for(int j=Log2 - 1;j>=0;j--){
        if(depth[jump[u][j]] >= depth[v]){
            u = jump[u][j];
        }
    }
    
    if(u == v) return u;
    
    for(int j=Log2 - 1;j>=0;j--){
        if(jump[u][j] != jump[v][j]){
            u = jump[u][j];
            v = jump[v][j];
        }
    }
    
    return jump[u][0];
}

int get_ans(int u, int p){
    
    ans[u] = values[u];
    
    for(int v:g[u]){
        if(v == p) continue;
        ans[u] += get_ans(v, u);
    }
    
    return ans[u];
}

int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].pb(b), g[b].pb(a);
    }
    
    dfs(0, 0);
    
    for(int q = 0;q<m;q++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        
        values[a] += 1;
        values[b] += 1;
        
        int lca = get_lca(a, b);
        
        values[lca] -= 1;
        if(lca) values[jump[lca][0]] -= 1;
    }
    
    get_ans(0, 0);
    
    for(int i=0;i<n;i++){
        cout<<ans[i]<<esp;
    }
}

/*

*/